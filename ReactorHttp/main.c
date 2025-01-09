/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 08:56:17 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

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

	return 0;
}