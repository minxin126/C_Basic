//// Client.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
#include "pch.h"
//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#include<WinSock2.h>
////#include <arpa/inet.h>
////#include <netinet/in.h>
////#include <sys/socket.h>
//#define MAXLINE 4096
//void clientWork(FILE* fp, int sockfd)
//{
//	char sendline[MAXLINE], receiveline[MAXLINE];
//	int n;
//	while (fgets(sendline, MAXLINE, fp) != NULL)
//	{
//		write(sockfd, sendline, strlen(sendline));
//		n = read(sockfd, receiveline, MAXLINE);
//		receiveline[n] = '\0';
//		fputs(receiveline, stdout);
//		if (strcmp(receiveline, "bye\n") == 0) break;
//	}
//}
//int main(int argc, char * * argv)
//{
//	int sockfd, n;
//	char recvline[MAXLINE + 1];
//	struct sockaddr_in servaddr;
//	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
//		printf("socket error\n");
//		exit(1);
//	}
//	memset(&servaddr, 0, sizeof(servaddr));
//	servaddr.sin_family = AF_INET;
//	servaddr.sin_port = htons(2000);//指定Server端的端口号
//	char * serverAddress = argv[1];
//	//判断指定的ip地址是否有错误
//	if (inet_pton(AF_INET, serverAddress, &servaddr.sin_addr) <= 0) {
//		printf("inet_pton error for %s\n", serverAddress);
//		exit(1);
//	}
//	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
//		printf("connect error\n");
//		exit(1);
//	}
//	//从Terminal中读取用户输入的指令
//	clientWork(stdin, sockfd);
//	close(sockfd);
//	return 0;
//}
//
//// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
//// 调试程序: F5 或调试 >“开始调试”菜单
//
//// 入门提示:
////   1. 使用解决方案资源管理器窗口添加/管理文件
////   2. 使用团队资源管理器窗口连接到源代码管理
////   3. 使用输出窗口查看生成输出和其他消息
////   4. 使用错误列表窗口查看错误
////   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
////   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件