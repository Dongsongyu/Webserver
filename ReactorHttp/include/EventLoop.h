/*************************************************************************
	> File Name: include/EventLoop.h
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 01:40:11 PM CST
 ************************************************************************/

#pragma once
#include "Dispatcher.h"

extern struct Dispatcher EpollDispatcher;
struct EventLoop {
	Dispatcher* dispatcher;
	void* dispatcherData;
};
