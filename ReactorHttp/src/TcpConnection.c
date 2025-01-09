/*************************************************************************
	> File Name: src/TcpConnection.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Jan 2025 04:46:12 PM CST
 ************************************************************************/

#include "TcpConnection.h"

int processRead(void* arg) {
	struct TcpConnection* conn = (struct TcpConnection*)arg;
	//接收数据
	int count = bufferSocketRead(conn->readBuf, conn->channel->fd);
	if (count > 0) {
		//接收到了 http 请求, 解析http请求
	} else {
		// 断开连接
		
	}
}

struct TcpConnection* tcpConnectionInit (int fd, struct EventLoop* evloop) {
	struct TcpConnection* conn = (struct TcpConnection*)malloc(sizeof(struct TcpConnection));
	conn->evLoop = evloop;
	conn->readBuf = bufferInit(10240);
	conn->writeBuf = bufferInit(10240);
	sprintf(conn->name, "Connection-%d", fd);
	conn->channel = channelInit(fd, ReadEvent, processRead, NULL, conn);
	eventLoopAddTask(evloop, conn->channel, ADD);

	return conn;
}

