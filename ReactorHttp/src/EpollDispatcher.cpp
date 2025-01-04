/*************************************************************************
	> File Name: src/EpollDispatcher.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 03:05:24 PM CST
 ************************************************************************/

#include "Dispatcher.h"
#include <sys/epoll.h>

#define MAX 520
struct EpollData {
	int epfd;
	struct epoll_event* events;
};

static void* epollInit ();
static int epollAdd (struct Channel* channel, struct EventLoop* evLoop);
static int epollRemove (struct Channel* channel, struct EventLoop* evLoop);
static int epollModify (struct Channel* channel, struct EventLoop* evLoop);
static int epollDispatch (struct EventLoop* evLoop, int timeout);//单位:s
static int epollClear (struct EventLoop* evLoop);
static int epollCtl(struct Channel* channel, struct EventLoop* evLoop, int op);

struct Dispatcher EpollDispatcher = {
	epollInit,
	epollAdd,
	epollRemove,
	epollModify,
	epollDispatch,
	epollClear
};

static void* epollInit () {
	struct EpollData* data = (struct EpollData *)malloc(sizeof(struct EpollData));
	data->epfd = epoll_create(10);
	if (data->epfd == -1) {
		perror("epoll_create");
		exit(0);
	}
	data->events = (struct epoll_event*)calloc(Max, sizeof(struct epoll_event));

	return data;
}

//如果发现代码中有冗余代码,一定要精简程序
static int epollCtl(struct Channel* channel, struct EventLoop* evLoop, int op) {
	struct EpollData* data = (struct EpollData*)evLoop->dispatcherData;
	struct epoll_event ev;
	ev.data.fd = channel->fd;
	int events = 0;
	if (channel->events & ReadEvent) {
		events |= EPOLLIN;
	}
	if (channel->events & WriteEvent) {
		events |= EPOLLOUT;
	}
	ev.events = events;
	int ret = epoll_ctl(data->epfd, op, channel->fd, &ev);
	return ret;
}

static int epollAdd (struct Channel* channel, struct EventLoop* evLoop) {
	int ret = epollCtl(channel, evLoop, EPOLL_CTL_ADD);
	if (ret == -1) {
		perror("epoll_ctl add");
		exit(0);
	}
	return ret;
}

static int epollRemove (struct Channel* channel, struct EventLoop* evLoop) {
	int ret = epollCtl(channel, evLoop, EPOLL_CTL_DEL);
	if (ret == -1) {
		perror("epoll_ctl delete");
		exit(0);
	}
	return ret;
}

static int epollModify (struct Channel* channel, struct EventLoop* evLoop) {
	int ret = epollCtl(channel, evLoop, EPOLL_CTL_MOD);
	if (ret == -1) {
		perror("epoll_ctl modify");
		exit(0);
	}
	return ret;
}

static int epollDispatch (struct EventLoop* evLoop, int timeout) {
	struct EpollData* data = (struct EpollData*)evLoop->dispatcherData;
	int count = epoll_wait(data->epfd, data->events, MAX, timeout * 1000);
	//将有效元素依次取出,再将有效元素对应的事件和文件描述符保存下来
	for (int i = 0; i < count; ++i) {
		int events = data->events[i].events;
		int fd = data->events[i].data.fd;
		//判断是否出现异常
		if (events & EPOLLERR || events & EPOLLHUP) {
			//对方断开连接,删除fd
			// epollRemove(Channel, evLoop);
			continue;
		}
		if (events & EPOLLIN) {

		}
		if (events & EPOLLOUT) {

		}
	}
	return 0;
}

static int epollClear (struct EventLoop* evLoop) {
	struct EpollData* data = (struct EpollData*)evLoop->dispatcherData;
	free(data->events);
	close(data->epfd);
	free(data);
}
