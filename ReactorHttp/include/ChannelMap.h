/*************************************************************************
	> File Name: ChannelMap.h
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 11:42:34 AM CST
 ************************************************************************/

#pragma once
#include<stdbool.h>

struct ChannelMap {
	int size; //记录指向的数组的元素个数
	//struct Channel* list[];
	struct Channel** list;
};

//初始化
struct ChannelMap* channelMapInit(int size);
//清空数据的函数
void ChannelMapClear(struct ChannelMap* map);
//重新分配内存空间
bool makeMapRoom(struct ChannelMap* map, int newSize, int unitSize);