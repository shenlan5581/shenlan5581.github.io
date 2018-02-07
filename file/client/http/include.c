// 邢柯公共函数

#ifndef _INCLUDE_C
#define _INCLUDE_C

#include "include.h"
#define sock_ntop_host(a, b) k_ntop(a)

char str[128];

char *k_ntop(struct sockaddr *addr)
{
	struct sockaddr_in *add;

	add = (struct sockaddr_in *)addr;

	inet_ntop(AF_INET, &(add->sin_addr.s_addr), &str, sizeof(str));
	return (str);
}

struct addrinfo *
host_serv(char *hostname, char *serv, int family, int socktype)
{
	int n;
	struct addrinfo hit, *res;
	hit.ai_flags = AI_CANONNAME;
	hit.ai_family = family;
	hit.ai_socktype = socktype;
	if ((getaddrinfo(hostname, serv, &hit, &res)) != 0)
	{
		printf("地址未找到\n");
		return (NULL);
		exit(0);
	}
	return (res);
}


void sock_set_port(struct sockaddr *addr, u_short port)
{
	struct sockaddr_in *addr_in;
	addr_in = (struct sockaddr_in *)addr;
	addr_in->sin_port = htons(port);
}

int sock_cmp_addr(const struct sockaddr *sa1, const struct sockaddr *sa2,
				  socklen_t salen)
{

	if (sa1->sa_family != sa2->sa_family)
	{
		return (-1);
	}
	return (memcmp(&((struct sockaddr_in *)sa1)->sin_addr,
				   &((struct sockaddr_in *)sa2)->sin_addr, salen));
}

void tv_sub(struct timeval *out, struct timeval *in)
{
	if ((out->tv_usec -= in->tv_usec) < 0)
	{
		--out->tv_sec;
		out->tv_usec += 1000000;
	}
	out->tv_sec -= in->tv_sec;
}

int sock_get_port(struct sockaddr *addr, socklen_t len)
{
	struct sockaddr_in *v4;
	int port;
	v4 = (struct sockaddr_in *)addr;
	port = v4->sin_port;

	return port; //返回端口号
}
struct sockaddr *create_IP4(char *host, int port)
{
	struct sockaddr_in *addr;
	struct sockaddr *sockaddr;

	addr = malloc(sizeof(32));
	addr->sin_family = AF_INET;
	addr->sin_port = htons(port);
	inet_pton(AF_INET, host, &addr->sin_addr);

	sockaddr = (struct sockaddr *)addr;
	couts(k_ntop(sockaddr));
	return sockaddr;
}

void create_IP4_2(char *host, int port, struct sockaddr *dest)
{
	struct sockaddr_in *addr;
	addr = (struct sockaddr_in *)dest;

	addr->sin_family = AF_INET;
	addr->sin_port = htons(port);
	inet_pton(AF_INET, host, &addr->sin_addr);
}

void echo_1(int sockfd) //带入socket 描述符
{
	int maxfdp1; //max of fd ;
	fd_set rset; // 描述符集合   read
	fd_set wset; // 描述符集合   write
	int n;
	char sendbuf[MAXBUF]; //字符缓冲
	char recvbuf[MAXBUF];
	char *src = "src:";
	char *des = "des:";
	if (sockfd < 2)
	{
		printf("描述符错误:%d\n", sockfd);
		exit(0);
	}

	FD_ZERO(&rset); //初始化

	for (;;)
	{
		FD_SET(1, &rset);					 //设置描述符
		FD_SET(sockfd, &rset);				 //设置描述符
		select(10, &rset, NULL, NULL, NULL); //调用select 阻塞于此

		if (FD_ISSET(1, &rset)) //终端可读
		{
			n = read(1, sendbuf, 1024);
			write(sockfd, sendbuf, n);
		}
		if (FD_ISSET(sockfd, &rset)) //如果sock可读
		{

			n = read(sockfd, recvbuf, 1024);
			if (n == 0 || n < 0 || n == 10) //如果读到0字符 函数返回
			{
				return;
			}
			write(2, des, 4);
			write(2, recvbuf, n);
		}
	}
}

void echo_2(int sockfd)
{

	int n;
	char sendbuf[MAXBUF]; //字符缓冲
	char recvbuf[MAXBUF];
	char *src = "src:";
	char *des = "des:";

	struct pollfd fd[2];
	fd[0].fd = sockfd;
	fd[0].events = POLLRDNORM;
	fd[1].fd = 1;
	fd[1].events = POLLRDNORM;
	for (;;)
	{
		n = poll(fd, 2, 10 * 1000);

		if (fd[0].revents & POLLRDNORM)
		{
			n = read(sockfd, recvbuf, 1024);
			if (n == 0 || n < 0 || n == 10) //如果读到0字符 函数返回
			{
				return;
			}
			write(2, des, 4);
			write(2, recvbuf, n);
		}
		if (fd[1].revents & POLLRDNORM)
		{
			n = read(1, sendbuf, 1024);
			write(sockfd, sendbuf, n);
		}
	}
}

int tcp_connect(struct sockaddr *desaddr)
{
	int fd;
	int n;

	fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	n = connect(fd, desaddr, 32);
	if (n < 0)
		printf("链接失败\n");

	return fd;
}
void space(int x,char a){
  int i ;
  for(i= 0;i<x;i++)
    printf("%c",a);
}
//********配置相关*********
 
/****** 简单输出************/
void echo_array(void *a,int len,int type)
{    if(type ==1 )  // integer
	   {     int  *arr;
		      arr = (int *)a;
			 int i ;
			 for( i = 0; i< len;i++)
			 {
               printf(" %d  ", arr[i]); 

			 }
			 printf("\n");
	   }
}
void couts(char *str)
{
	printf("%s", str);
}    
void coutd(int x)
{
	printf("%d", x);
}    
		

  

#endif