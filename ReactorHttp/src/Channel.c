/*************************************************************************
	> File Name: Channel.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 09:27:17 AM CST
 ************************************************************************/

#include "Channel.h"
#include <stdlib.h>

struct Channel* channelInit(int fd, int events, handleFunc readFunc, handleFunc writeFunc, handleFunc destroyFunc, void *arg)
{
	struct Channel* channel = (struct Channel*)malloc(sizeof(struct Channel));
	channel->arg = arg;
	channel->fd = fd;
	channel->events = events;
	channel->readCallback = readFunc;
	channel->writeCallback = writeFunc;
	channel->destroyCallback = destroyFunc;
	return channel;
}

void writeEventEnable(struct Channel* channel, bool flag) {
	if (flag) {
		//将channel->events第三个标志位置为1
		channel->events |= WriteEvent;
	}
	else {
		//将channel->events第三个标志位清零
		channel->events = channel->events & ~WriteEvent;
	}
}

bool isWriteEventEnable(struct Channel* channel) {
	return channel->events & WriteEvent;
}