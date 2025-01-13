/*************************************************************************
	> File Name: Channel.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Jan 2025 01:50:40 PM CST
 ************************************************************************/

#include<iostream>
#include "Channel.h"

Channel::Channel (int fd, int events, handleFunc readFunc, handleFunc writeFunc, handleFunc destroyFuc, void *arg) {
	m_arg = arg;
	m_fd = fd;
	m_events = events;
	readCallback = readFunc;
	writeCallback = writeFunc;
	destroyCallback = destroyFunc;
}

void Channel::writeEventEnable(bool flag) {
	if (flag) {
		//将channel->events第三个标志位置为1
		m_events |= static_cast<int>(FDEvent::WriteEvent);
	}
	else {
		//将channel->events第三个标志位清零
		m_events = m_events & ~static_cast<int>(FDEvent::WriteEvent);
	}
}

bool Channel::isWriteEventEnable() {
	return m_events & static_cast<int>(FDEvent::WriteEvent);
}