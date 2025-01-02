/*************************************************************************
	> File Name: 1.socket.c
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Jan 2025 07:19:31 PM CST
 ************************************************************************/

#include<stdio.h>
#include"server.h"
#include<arpa/inet.h>
#include<sys/epoll.h>
#include<fcntl.h>

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
	ret = bind(lfd, (struct sockaddr*)&addr, sizeof addr);
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

	while(1) {
		int size = sizeof(evs) / sizeof(struct epoll_event);//这个数组中共有多少结构体元素
		//没有任何事件被激活，可以阻塞时长，当时长到达，就可以解除阻塞
		//如果最后一个参数为0,即使没有事件，也不会阻塞，返回值为0
		//最后一个参数为-1，直到有时间触发才会解除阻塞
		int num = epoll_wait(epfd, evs, size, -1);
		for (int i = 0; i < num; ++i) {
			int fd = evs[i].data.fd;
			if (fd == lfd) {
				//建立新连接 accept
				appeptClient(lfd, epfd);
			}
			else {
				//主要是接收对端的数据
			}
		}
	}

	return 0;
}

int acceptClient(int lfd, int epfd) {
	//建立连接
	int cfd = accept(lfd, NULL, NULL);
	if(cfd == -1) {
		perror("accept");
		return -1;
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
	int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
	if (ret == -1) {
		perror("epoll_ctl");
		return -1;
	}

	return 0;
}