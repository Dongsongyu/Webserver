/*************************************************************************
	> File Name: src/TcpServer.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Jan 2025 10:59:08 AM CST
 ************************************************************************/

#include "TcpServer.h"
#include "TcpConnection.h"
#include <arpa/inet.h>

struct TcpServer* tcpServerInit(unsigned short port, int threadNum) {
	struct TcpServer* tcp = (struct TcpServer*)malloc(sizeof(struct TcpServer));
	tcp->listener = listenerInit(port);
	tcp->mainLoop = eventLoopInit();
	tcp->threadNum = threadNum;
	tcp->threadPool = threadPoolInit(tcp->mainLoop, threadNum);
	return tcp;
}

struct Listener* listenerInit(unsigned short port) {
	struct Listener* listener = (struct Listener*)malloc(sizeof(struct Listener));
	//创建用于监听的文件描述符
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	if(lfd == -1) {
		perror("socket");
		return NULL;
	}
	int opt = 1;
	//当主动断开连接的一方断开连接之后需要在一分钟之后才能释放绑定端口,没释放前不能再次使用
	int ret = setsockopt(lfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));
	if (ret == -1) {
		perror("setsockopt");
		return NULL;
	}
	//使用文件描述符绑定本地ip和端口
	struct sockaddr_in addr;
	//地址簇协议,指定使用ipv4还是ipv6
	addr.sin_family = AF_INET;
	//指定端口
	//初始化端口时需要把端口从小端转大端
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY; //0地址,表示可以绑定本地所有ip地址
	ret = bind(lfd, (struct sockaddr*)&addr, sizeof(addr));
	if (ret == -1) {
		perror("bind");
		return NULL;
	}
	//给监听的文件描述符设置监听
	ret = listen(lfd, 128);
	if (ret == -1) {
		perror("listen");
		return NULL;
	}
	//返回fd
	listener->lfd = lfd;
	listener->port = port;
	return listener;
}

int acceptConnection (void* arg) {
	struct TcpServer* server = (struct TcpServer*)arg;
	// 和客户端建立连接
	int cfd = accept(server->listener->lfd, NULL, NULL);
	// 从线程池中取出一个子线程的反应堆实例,去处理这个cfd
	struct EventLoop* evLoop = takeWorkerEventLoop(server->threadPool);
	// 将cfd放到TcpConnection中处理
	tcpConnectionInit(cfd, evLoop);
}

void tcpServerRun(struct TcpServer* server) {
	// 启动线程池
	threadPoolRun(server->threadPool);
	// 添加检测的任务
	//初始化一个channel实例
	struct Channel* channel = channelInit(server->listener->lfd, 
		ReadEvent, acceptConnection, NULL, server);
	eventLoopAddTask(server->mainLoop, channel, ADD);
	// 启动反应堆模型
	eventLoopRun(server->mainLoop);
}