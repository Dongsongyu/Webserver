/*************************************************************************
	> File Name: Dispatcher.h
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 01:13:32 PM CST
 ************************************************************************/

#pragma once
#include "Channel.h"
#include "EventLoop.h"

struct Dispatcher {
	//init -- 初始化epoll, poll或者select需要的数据块
	void (*init) ();
	//添加
	int (*add) (struct Channel* channel, struct EventLoop* evLoop);
	//删除
	int (*remove) (struct Channel* channel, struct EventLoop* evLoop);
	//修改
	int (*modify) (struct Channel* channel, struct EventLoop* evLoop);
	//事件监测
	//1.函数指针指向epoll
	//调用epoll_wait()来监测哪些文件描述符对应的事件发生变化，如果有被激活的文件描述符
	//这一系列被激活的文件描述符的集合就会存储在epoll_wait()第二个参数里面,是epoll_event类型
	//2.函数指针指向poll
	//调用poll()函数
	//3.函数指针指向select()
	//判断select的读集合和写集合
	int (*dispatch) (struct EventLoop* evLoop, int timeout);//单位:s
	//清除数据
	int (*clear) (struct EventLoop* evLoop);
};
