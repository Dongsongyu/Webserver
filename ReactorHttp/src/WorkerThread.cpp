/*************************************************************************
	> File Name: WorkerThread.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Jan 2025 04:01:41 PM CST
 ************************************************************************/

#include "WorkerThread.h"

int workerThreadInit(struct WorkerThread* thread, int index) {
	thread->evLoop = NULL;
	thread->threadID = 0;
	sprintf(thread->name, "SubThread-%d", index);
	//指定为NULL,表示使用默认属性
	pthread_mutex_init(&thread->mutex, NULL);
	pthread_cond_init(&thread->cond, NULL);
	return 0;
}

// 子线程的回调函数
void* subThreadRunnig(void* arg) {
	struct WorkerThread* thread = (struct WorkerThread*)arg;
	pthread_mutex_lock(&thread->mutex);
	thread->evLoop = eventLoopInitEx(thread->name);
	pthread_mutex_unlock(&thread->mutex);
	pthread_cond_signal(&thread->cond);
	eventLoopRun(thread->evLoop);
	return NULL;
}

void workerThreadRun(struct WorkerThread* thread) {
	//创建子线程
	//反应堆模型是在WorkerThrea里面,把当前WorkerThread这个实例传给第四个参数(回调函数)
	pthread_create(&thread->threadID, NULL, subThreadRunnig, thread);
	//阻塞主线程,让当前函数不会直接结束
	pthread_mutex_lock(&thread->mutex);
	while (thread->evLoop == NULL) {
		pthread_cond_wait(&thread->cond, &thread->mutex);
	}
	pthread_mutex_unlock(&thread->mutex);
}
