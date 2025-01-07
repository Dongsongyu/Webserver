/*************************************************************************
	> File Name: include/TcpServer.h
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Jan 2025 10:58:55 AM CST
 ************************************************************************/

#pragma once
#include "EventLoop.h"
#include "ThreadPool.h"

struct Listener {
	int lfd;
	unsigned short port;
};

struct TcpServer {
	int threadNum;
	struct EventLoop* mainLoop;
	struct ThreadPool* threadPool;
	struct Listener* listener;
};

// 初始化
struct TcpServer* tcpServerInit(unsigned short port, int threadNum);
// 初始化监听
struct Listener* listenerInit(unsigned short port);
// 启动服务器
void tcpServerRun(struct TcpServer* server);
//取出线程池中某个子线程的反应堆实例
struct EventLoop* takeWorkerEventLoop(struct ThreadPool* pool);