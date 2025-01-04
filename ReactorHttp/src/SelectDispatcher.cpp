/*************************************************************************
	> File Name: src/SelectDispatcher.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 07:09:33 PM CST
 ************************************************************************/

#include "Dispatcher.h"
#include <sys/select.h>
#include <stdio.h>

#define MAX 1024
struct SelectData {
	fd_set readSet;
	fd_set writeSet;
};

static void* selectInit ();
static int selectAdd (struct Channel* channel, struct EventLoop* evLoop);
static int selectRemove (struct Channel* channel, struct EventLoop* evLoop);
static int selectModify (struct Channel* channel, struct EventLoop* evLoop);
static int selectDispatch (struct EventLoop* evLoop, int timeout);//单位:s
static int selectClear (struct EventLoop* evLoop);
static void setFdSet(struct Channel* channel, struct SelectData* data);
static void clearFdSet(struct Channel* channel, struct SelectData* data);

struct Dispatcher SelectDispatcher = {
	selectInit,
	selectAdd,
	selectRemove,
	selectModify,
	selectDispatch,
	selectClear
};

static void* selectInit () {
	struct SelectData* data = (struct SelectData *)malloc(sizeof(struct SelectData));
	FD_ZERO(&data->readSet);
	FD_ZERO(&data->writeSet);

	return data;
}

static void setFdSet(struct Channel* channel, struct SelectData* data) {
	if (channel->events & ReadEvent) {
		FD_SET(channel->fd, &data->readSet);
	}
	if (channel->events & WriteEvent) {
		FD_SET(channel->fd, &data->writeSet);
	}
}
static void clearFdSet(struct Channel* channel, struct SelectData* data) {
	if (channel->events & ReadEvent) {
		FD_CLR(channel->fd, &data->readSet);
	}
	if (channel->events & WriteEvent) {
		FD_CLR(channel->fd, &data->writeSet);
	}
}

static int SelectAdd (struct Channel* channel, struct EventLoop* evLoop) {
	struct SelectData* data = (struct SelectData *)malloc(sizeof(struct SelectData));
	if (channel->fd >= MAX) {
		return -1;
	}
	setFdSet(channel, data);
	
	return 0;
}

static int SelectRemove (struct Channel* channel, struct EventLoop* evLoop) {
	struct SelectData* data = (struct SelectData *)malloc(sizeof(struct SelectData));
	clearFdSet(channel, data);
	return 0;
}

static int SelectModify (struct Channel* channel, struct EventLoop* evLoop) {
	struct SelectData* data = (struct SelectData *)malloc(sizeof(struct SelectData));
	setFdSet(channel, data);
	clearFdSet(channel, data);
	return 0;
}

static int selectDispatch (struct EventLoop* evLoop, int timeout) {
	struct SelectData* data = (struct SelectData *)malloc(sizeof(struct SelectData));
	struct timeval val;
	//最后是将sec+usec,所以必须初始化0,如果不初始化，就会随机数
	val.tv_sec = timeout;
	val.tv_usec = 0;
	//数据库传给内核，内核经过检测，会重写这个数据库里面的数据
	//多次调用这个函数，则对应的文件描述符越来越少,所以需要数据备份
	fd_set rdtmp = data->readSet;
	fd_set wrtmp = data->writeSet;
	int count = select(MAX, &rdtmp, &wrtmp, NULL, &val);
	if (count == -1) {
		perror("select");
		exit(0);
	}
	for (int i = 0; i < MAX; ++i) {
		if (FD_ISSET(i, &rdtmp)) {
			
		}

		if (FD_ISSET(i, &wrtmp)) {

		}
	}
	return 0;
}

static int selectClear (struct EventLoop* evLoop) {
	struct SelectData* data = (struct SelectData *)malloc(sizeof(struct SelectData));
	free(data);
}
