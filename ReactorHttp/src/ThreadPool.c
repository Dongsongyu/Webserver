/*************************************************************************
	> File Name: include/ThreadPool.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Jan 2025 06:51:35 PM CST
 ************************************************************************/

#include "ThreadPool.h"
#include "WorkerThread.h"
#include <assert.h>

struct ThreadPool* threadPoolInit(struct EventLoop* mainLoop, int count) {
	struct ThreadPool* pool = (struct ThreadPool*)malloc(sizeof(struct ThreadPool));
	pool->index = 0;
	pool->isStart = false;
	pool->mainLoop = mainLoop;
	pool->threadNum = count;
	pool->workerThreads = (struct WorkerThread*)malloc(sizeof(struct WorkerThread) * count);

	return pool;
}

void threadPoolRun(struct ThreadPool* pool) {
	assert(pool && !pool->isStart);
	//判断执行这个的函数的线程是不是主线程
	if (pool->mainLoop->threadID != pthread_self()) {
		exit(0);
	}
	pool->isStart = true;
	if (pool->threadNum) {
		for (int i = 0; i < pool->threadNum; ++i) {
			workerThreadInit(&pool->workerThreads[i], i);
			workerThreadRun(&pool->workerThreads[i]);
		}
	}
}

struct EventLoop* takeWorkerEventLoop(struct ThreadPool* pool) {
	assert(pool->isStart);
	if (pool->mainLoop->threadID != pthread_self()) {
		exit(0);
	}
	// 从线程池中找一个子线程，然后取出里面的反应堆实例
	struct EventLoop* evLoop = pool->mainLoop;
	if (pool->threadNum > 0) {
		evLoop = pool->workerThreads[pool->index].evLoop;
		pool->index = ++pool->index % pool->threadNum;
	}

	return evLoop;
}