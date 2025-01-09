/*************************************************************************
	> File Name: include/TcpConnection.h
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Jan 2025 04:39:37 PM CST
 ************************************************************************/

#pragma once
#include "EventLoop.h"
#include "Buffer.h"
#include "Channel.h"

struct TcpConnection {
	struct EventLoop* evLoop;
	struct Channel* channel;
	struct Buffer* readBuf;
	struct Buffer* writeBuf;
	char name[32];
};

// 初始化
struct TcpConnection* tcpConnectionInit (int fd, struct EventLoop* evloop);

