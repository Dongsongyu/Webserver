/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Jan 2025 07:41:54 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

int main(int argc, char* argv[])
{
	//需要把服务器进程切换到用户指定目录下面
	if (argc < 3) {
		printf("./a.out port path\n");
		return -1;
	}
	unsigned short port = atoi(argv[1]);
	//切换服务器的工作路径
	chdir(argv[2]);
	//初始化用于监听的套接字
	int lfd = initListenFd(port);//取值范围是0-65535
	//启动epoll，启动服务器程序
	epollRun(lfd);

	return 0;
}
