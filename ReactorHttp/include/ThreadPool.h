/*************************************************************************
	> File Name: include/ThreadPool.h
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Jan 2025 06:51:43 PM CST
 ************************************************************************/

#pragma once
#include "EventLoop.h"
#include "WorkerThread.h"
#include <stdbool.h>
#include <stdlib.h>

// 定义线程池
struct ThreadPool {
	//主线程的反应堆模型
	struct EventLoop* mainLoop;
	bool isStart; //标记线程池是否启动
	//记录子线程的总数量
	int threadNum;
	struct WorkerThread* workerThreads;
	int index;
};

//初始化线程池
struct ThreadPool* threadPoolInit(struct EventLoop* mainLoop, int count);
//启动线程池
void threadPoolRun(struct ThreadPool* pool);
// 取出线程池某个子线程的反应堆实例
struct EventLoop* takeWorkerEventLoop(struct ThreadPool* pool);