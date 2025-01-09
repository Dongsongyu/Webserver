/*************************************************************************
	> File Name: ChannelMap.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 11:42:26 AM CST
 ************************************************************************/

#include "ChannelMap.h"
#include <stdio.h>
#include <stdlib.h>

struct ChannelMap* channelMapInit(int size) {
	struct ChannelMap* map = (struct ChannelMap*)malloc(sizeof(struct ChannelMap));
	map->size = size;
	map->list = (struct Channel**)malloc(size * sizeof(struct Channel*));

	return map;
}

void ChannelMapClear(struct ChannelMap* map) {
	if (map != NULL) {
		for(int i = 0; i < map->size; ++i) {
			if(map->list[i] != NULL) {
				free(map->list[i]);
			}
		}
		free(map->list);
		map->list = NULL;
	}
	map->size = 0;
}

bool makeMapRoom(struct ChannelMap* map, int newSize, int unitSize) {
	if (map->size < newSize) {
		int curSize = map->size;
		//容量每次扩大原来的一倍
		while (curSize < newSize) {
			curSize *= 2;
		}
		//扩容 realloc
		//返回指针 void *realloc(void *ptr, size_t size);
		struct Channel** temp = realloc(map->list, curSize * unitSize);
		if (temp == NULL) {
			return false;
		}
		map->list = temp;
		memset(&map->list[map->size], 0, (curSize - map->size) * unitSize);
		map->size = curSize;
	}

	return true;
}