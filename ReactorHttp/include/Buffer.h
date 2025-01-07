/*************************************************************************
	> File Name: include/Buffer.h
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Jan 2025 07:33:36 PM CST
 ************************************************************************/

#pragma once

struct Buffer {
	//指向内存的指针
	void* data;
	int capacity;
	int readPos;
	int writePos;
};

// 初始化Buffer
struct Buffer* bufferInit(int size);
// 销毁内存
void bufferDestroy(struct Buffer* buf);
//扩容
void bufferExtendRoom(struct Buffer* buffer, int size);
//得到剩余的可写的内存容量
int bufferWriteableSize(struct Buffer* buffer);
//得到剩余的可读的内存容量
int bufferReadableSize(struct Buffer* buffer);
//写内存 1.直接写 2.接收套接字数据
int bufferAppendData(struct Buffer* buffer, const char* data, int size);
int bufferAppendString(struct Buffer* buffer, const char* data);
int bufferSocketRead(struct Buffer* buffer, int fd);