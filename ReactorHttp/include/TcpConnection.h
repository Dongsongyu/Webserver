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
#include "HttpRequest.h"
#include "HttpResponse.h"

#define MSG_SEND_AUTO

struct TcpConnection {
	struct EventLoop* evLoop;
	struct Channel* channel;
	struct Buffer* readBuf;
	struct Buffer* writeBuf;
	char name[32];
	// http 协议
	struct HttpRequest* request;
	struct HttpResponse* response;
};

// 初始化
struct TcpConnection* tcpConnectionInit (int fd, struct EventLoop* evloop);
// 资源释放
int tcpConnectionDestroy (void* conn);
