/*************************************************************************
	> File Name: include/TcpServer.h
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Jan 2025 09:33:07 AM CST
 ************************************************************************/

#pragma once
#include "EventLoop.h"
#include "ThreadPool.h"

class TcpServer
{
public:
    TcpServer(unsigned short port, int threadNum);
    // 初始化监听
    void setListen();
    // 启动服务器
    void run();
	//作为Channel的回调函数
    static int acceptConnection(void* arg);

private:
    int m_threadNum;
    EventLoop* m_mainLoop;
    ThreadPool* m_threadPool;
    int m_lfd;
    unsigned short m_port;
};

