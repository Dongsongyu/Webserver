/*************************************************************************
	> File Name: include/TcpConnection.h
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Jan 2025 03:22:59 PM CST
 ************************************************************************/

#pragma once
#include "EventLoop.h"
#include "Buffer.h"
#include "Channel.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

//#define MSG_SEND_AUTO

class TcpConnection
{
public:
    TcpConnection(int fd, EventLoop* evloop);
    ~TcpConnection();

    static int processRead(void* arg);
    static int processWrite(void* arg);
    static int destroy(void* arg);
private:
    string m_name;
    EventLoop* m_evLoop;
    Channel* m_channel;
    Buffer* m_readBuf;
    Buffer* m_writeBuf;
    // http 协议
    HttpRequest* m_request;
    HttpResponse* m_response;
};
