/*************************************************************************
	> File Name: 1.socket.c
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Jan 2025 07:19:31 PM CST
 ************************************************************************/

#include "server.h"
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <strings.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/sendfile.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>

//cmake -S . -B build/    
//cmake --build build/   
struct FdInfo
{
    int fd;
    int epfd;
    pthread_t tid;
};

int initListenFd(unsigned short port) {
	//创建监听的fd
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	if(lfd == -1) {
		perror("socket");
		return -1;
	}
	//设置端口复用
	int opt = 1;
	//当主动断开连接的一方断开连接之后需要在一分钟之后才能释放绑定端口,没释放前不能再次使用
	int ret = setsockopt(lfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));
	if (ret == -1) {
		perror("setsockopt");
		return -1;
	}
	//绑定端口
	struct sockaddr_in addr;
	//地址簇协议,指定使用ipv4还是ipv6
	addr.sin_family = AF_INET;
	//指定端口
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	ret = bind(lfd, (struct sockaddr*)&addr, sizeof(addr));
	if (ret == -1) {
		perror("bind");
		return -1;
	}
	//设置监听
	ret = listen(lfd, 128);
	if (ret == -1) {
		perror("listen");
		return -1;
	}
	//返回fd
	return lfd;
}

int epollRun(int lfd) {
	//创建epoll实例
	//如果参数为0,则创建失败
	int epfd = epoll_create(1);
	if (epfd == -1) {
		perror("epoll_create");
		return -1;
	}

	//lfd上树
	struct epoll_event ev;
	//记录当前要操作的文件描述符
	ev.data.fd = lfd;
	ev.events = EPOLLIN;
	int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
	if (ret == -1) {
		perror("epoll_ctl");
		return -1;
	}
	//检测
	struct epoll_event evs[1024];
	int size = sizeof(evs) / sizeof(struct epoll_event);//这个数组中共有多少结构体元素
	while(1) {
		//没有任何事件被激活，可以阻塞时长，当时长到达，就可以解除阻塞
		//如果最后一个参数为0,即使没有事件，也不会阻塞，返回值为0
		//最后一个参数为-1，直到有时间触发才会解除阻塞
		int num = epoll_wait(epfd, evs, size, -1);
		for (int i = 0; i < num; ++i) {
			struct FdInfo* info = (struct FdInfo *)malloc(sizeof(struct FdInfo));
			int fd = evs[i].data.fd;
			info->epfd = epfd;
			info->fd = fd;
			if (fd == lfd) {
				//建立新连接 accept
				//acceptClient(lfd, epfd);
				pthread_create(&info->tid, NULL, acceptClient, info);
			}
			else {
				//主要是接收对端的数据
				//recvHttpRequest(fd, epfd);
				pthread_create(&info->tid, NULL, recvHttpRequest, info);
			}
		}
	}

	return 0;
}

//int acceptClient(int lfd, int epfd)
void* acceptClient(void* arg) {
	//此处结构体中存储的lfd和epfd不需要关闭
	struct FdInfo* info = (struct FdInfo*)arg;
	//建立连接
	int cfd = accept(info->fd, NULL, NULL);
	if(cfd == -1) {
		perror("accept");
		return NULL;
	}
	//设置非阻塞
	int flag = fcntl(cfd, F_GETFL);
	flag |= O_NONBLOCK;
	fcntl(cfd, F_SETFL, flag);

	//cfd添加到epoll中
	struct epoll_event ev;
	//记录当前要操作的文件描述符
	ev.data.fd = cfd;
	ev.events = EPOLLIN | EPOLLET;
	int ret = epoll_ctl(info->epfd, EPOLL_CTL_ADD, cfd, &ev);
	if (ret == -1) {
		perror("epoll_ctl");
		return NULL;
	}
	printf("acceotcliet threadId: %ld\n", info->tid);
	free(info);

	return NULL;
}

//int recvHttpRequest(int cfd, int epfd)
void* recvHttpRequest(void* arg) {
	//此处结构体中通信的文件描述符,fd需要关闭,epfd不需要关闭
	struct FdInfo* info = (struct FdInfo*)arg;
	printf("开始接收数据...\n");
	int len = 0, totle = 0;
	//防止数据覆盖,再创建一个buff
	char tmp[1024] = {0};
	char buf[4096] = {0};
	//防止数据覆盖，每次都拷贝
	while ((len = recv(info->fd, tmp, sizeof(tmp), 0)) > 0) {
		if (totle + len < sizeof(buf)) {
			memcpy(buf + totle, tmp, len);
		}	
		totle += len;
	}
	//判断数据是否被接收完毕
	if (len == -1 && errno == EAGAIN) {
		//解析请求行
		char* pt = strstr(buf, "\r\n");
		int reqLen = pt - buf;
		buf[reqLen] = '\0';
		parseRequestLine(buf, info->fd);
	} 
	else if (len == 0) {
		//客户端断开连接
		epoll_ctl(info->epfd, EPOLL_CTL_DEL, info->fd, NULL);
		close(info->fd);
	}
	else {
		perror("recv");
	}
	printf("recvMsg threadId: %ld\n", info->tid);
	free(info);

	return NULL;
}

int parseRequestLine(const char* line, int cfd) {
	//解析请求行 get /xxx/1.jpg http/1.1
	char method[12];
	char path[1024];
	sscanf(line, "%[^ ] %[^ ]", method, path);
	printf("method: %s, path: %s\n", method, path);
	if(strcasecmp(method, "get") != 0) {
		return -1;
	}
	decodeMsg(path, path);
	//处理客户端请求的静态资源(目录或者文件)
	char* file = NULL;
	if (strcmp(path, "/") == 0) {
		file = "./";
	} else {
		file = path + 1;
	}
	//获取文件属性
	struct stat st;
	int ret = stat(file, &st);
	if (ret == -1) {
		//文件不存在 -- 回复404
		sendHeadMsg(cfd, 404, "Not Found", getFileType(".html"), -1);
        sendFile("404.html", cfd);
        return 0;
	}
	//判断文件类型
	if (S_ISDIR(st.st_mode)) {
		//把这个目录中的内容发送给客户端
		sendHeadMsg(cfd, 200, "OK", getFileType(".html"), -1);
		sendDir(file, cfd);
	} else {
		//把文件的内容发送给客户端
		sendHeadMsg(cfd, 200, "OK", getFileType(file), st.st_size);
		sendFile(file, cfd);
	}

	return 0;
}

const char* getFileType(const char* name) {
	 // a.jpg a.mp4 a.html
    // 自右向左查找‘.’字符, 如不存在返回NULL
    const char* dot = strrchr(name, '.');
    if (dot == NULL)
        return "text/plain; charset=utf-8";	// 纯文本
    if (strcmp(dot, ".html") == 0 || strcmp(dot, ".htm") == 0)
        return "text/html; charset=utf-8";
    if (strcmp(dot, ".jpg") == 0 || strcmp(dot, ".jpeg") == 0)
        return "image/jpeg";
    if (strcmp(dot, ".gif") == 0)
        return "image/gif";
    if (strcmp(dot, ".png") == 0)
        return "image/png";
    if (strcmp(dot, ".css") == 0)
        return "text/css";
    if (strcmp(dot, ".au") == 0)
        return "audio/basic";
    if (strcmp(dot, ".wav") == 0)
        return "audio/wav";
    if (strcmp(dot, ".avi") == 0)
        return "video/x-msvideo";
    if (strcmp(dot, ".mov") == 0 || strcmp(dot, ".qt") == 0)
        return "video/quicktime";
    if (strcmp(dot, ".mpeg") == 0 || strcmp(dot, ".mpe") == 0)
        return "video/mpeg";
    if (strcmp(dot, ".vrml") == 0 || strcmp(dot, ".wrl") == 0)
        return "model/vrml";
    if (strcmp(dot, ".midi") == 0 || strcmp(dot, ".mid") == 0)
        return "audio/midi";
    if (strcmp(dot, ".mp3") == 0)
        return "audio/mpeg";
    if (strcmp(dot, ".ogg") == 0)
        return "application/ogg";
    if (strcmp(dot, ".pac") == 0)
        return "application/x-ns-proxy-autoconfig";

    return "text/plain; charset=utf-8";

}

int sendDir(const char* dirName, int cfd) {
	char buf[4096] = { 0 };
    sprintf(buf, "<html><head><title>%s</title></head><body><table>", dirName);
    struct dirent** namelist;
    int num = scandir(dirName, &namelist, NULL, alphasort);
    for (int i = 0; i < num; ++i) {
		//取出文件名
		//namelist指向的是一个指针数组 struct dirent* tmp[]
		char* name = namelist[i]->d_name;
        struct stat st;
        char subPath[1024] = { 0 };
        sprintf(subPath, "%s/%s", dirName, name);
        stat(subPath, &st);
		//如果是目录，按照目录处理，如果是非目录，按照文件方式处理
		if (S_ISDIR(st.st_mode)) {
			// a标签 <a href = "">name</a>
			//如果要跳转到某个目录里面,那么这个href对应的连接要加/
			sprintf(buf + strlen(buf), 
			"<tr><td><a href = \"%s/\">%s</a></td><td>%ld</td></tr>", 
			name, name, st.st_size);
		} else {
			sprintf(buf + strlen(buf), 
			"<tr><td><a href = \"%s\">%s</a></td><td>%ld</td></tr>", 
			name, name, st.st_size);
		}
		send(cfd, buf, strlen(buf), 0);
		memset(buf, 0, sizeof(buf));
		free(namelist[i]);
	}
	sprintf(buf, "</table><body></html>");
	send(cfd, buf, strlen(buf), 0);
	free(namelist);
	return 0;
}

int sendFile(const char* fileName, int cfd) {
	//打开文件
	int fd = open(fileName, O_RDONLY);
	if (fd < 0) { // 检查文件是否成功打开
        perror("Failed to open file");
        return -1; // 返回错误
    }
	assert(fd > 0);//大于0说明文件描述符没问题,如果不大于0,则断言失败
#if 0
	while (1) {
		char buf[1024];
		int len = read(fd, buf, sizeof(buf));
		if (len > 0) { //从文件中读出了数据块
			send(cfd, buf, len, 0);
			usleep(10);//这非常重要
		}
		else if (len == 0) { //文件内容读完了
			break;
		}
		else {//出现异常
			perror("read");
		}
	}
#else
	//关于sendfile的第三个参数offset:
	//发送数据之前,根据该偏移量开始读文件数据
	//发送数据之后,更新该偏移量
	off_t offset = 0;
	//使用 lseek(fd, 0, SEEK_END) 确定文件大小后，需要重置文件偏移量到文件开头（
	//lseek(fd, 0, SEEK_SET)），
	//但如果中途 lseek 调用出错，可能会导致偏移量不正确。
	// int size = lseek(fd, 0, SEEK_END);
	// lseek(fd, 0, SEEK_SET);
	struct stat statBuf;
    if (fstat(fd, &statBuf) < 0) { // 获取文件大小
        perror("Failed to get file stats");
        close(fd);
        return -1;
    }
    int fileSize = statBuf.st_size;

	while (offset < fileSize) {
        int ret = sendfile(cfd, fd, &offset, fileSize - offset);
        if (ret < 0) {
            if (errno == EAGAIN) {
                // EAGAIN 表示当前不可写，通常用于非阻塞 socket
                usleep(10000); // 等待 10ms
                continue;
            } else {
                perror("sendfile failed");
                close(fd);
                return -1;
            }
        }
        printf("Bytes sent: %d, Offset: %ld\n", ret, offset);
    }
#endif
    close(fd); // 关闭文件描述符
    return 0;
}

int sendHeadMsg(int cfd, int status, const char* descr, const char* type, int length) {
	//状态行
	char buf[4096] = {0};
	sprintf(buf, "http/1.1 %d %s\r\n", status, descr);
	//响应头
	sprintf(buf + strlen(buf), "content-type: %s\r\n", type);
	sprintf(buf + strlen(buf), "content-length: %d\r\n\r\n", length);//length结束后还有个空行

	send(cfd, buf, strlen(buf), 0);
	//http响应数据块指的是http响应的第四部分
	return 0;
}

// 将字符转换为整形数
int hexToDec(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;

    return 0;
}

// 解码
// to 存储解码之后的数据, 传出参数, from被解码的数据, 传入参数
void decodeMsg(char* to, char* from)
{
    for (; *from != '\0'; ++to, ++from)
    {
        // isxdigit -> 判断字符是不是16进制格式, 取值在 0-f
        // Linux%E5%86%85%E6%A0%B8.jpg
        if (from[0] == '%' && isxdigit(from[1]) && isxdigit(from[2]))
        {
            // 将16进制的数 -> 十进制 将这个数值赋值给了字符 int -> char
            // B2 == 178
            // 将3个字符, 变成了一个字符, 这个字符就是原始数据
            *to = hexToDec(from[1]) * 16 + hexToDec(from[2]);

            // 跳过 from[1] 和 from[2] 因此在当前循环中已经处理过了
            from += 2;
        }
        else
        {
            // 字符拷贝, 赋值
            *to = *from;
        }

    }
    *to = '\0';
}
