/*************************************************************************
	> File Name: Channel.h
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Jan 2025 01:50:49 PM CST
 ************************************************************************/

#pragma once

//定义函数指针
//typedef int(*handleFunc)(void* arg);
using handleFunc = int(*)(void*);

//定义文件描述符的读写事件
enum class FDEvent {
	TimeOut = 0x01, //超时
	ReadEvent = 0x02,
	WriteEvent = 0x04
};

class Channel {
public:
	Channel(int fd, int events, handleFunc readFunc, 
	handleFunc writeFunc, handleFunc destroyFuc, void *arg);
	//回调函数
	handleFunc readCallback;
	handleFunc writeCallback;
	handleFunc destroyCallback;
	//修改fd的写事件(检测or不检测)
	//如果flag为true,则检测，否则不检测
	void writeEventEnable(bool flag);
	//判断是否需要检测文件描述符的写事件
	bool isWriteEventEnable();
	// 取出私有成员的值
	inline int getEvent() {
		return m_events;
	}
	inline int getFd() {
		return m_fd;
	}
	inline const void* getArg() {
		return m_arg;
	}
private:
	//文件描述符
	int m_fd;
	//事件
	int m_events;
	//回调函数的参数
	void* m_arg;
};
