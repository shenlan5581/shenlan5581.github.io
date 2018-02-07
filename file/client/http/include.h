
#ifndef _include_h
#define _include_h

#include <stdio.h>    //输入输出
#include <errno.h>    //错误标识
#include <sys/wait.h> //进程等待
#include <stdlib.h>   //
#include <sys/stat.h> //文件结构stat
#include <unistd.h>   //文件权限access
#include <setjmp.h>   //跳转
#include <time.h>     //时间
#include <pthread.h>  //线程
#include <fcntl.h>    //标准IO
#include <string.h>
#include <sys/ioctl.h>
#include <netdb.h>      //网络
#include <sys/socket.h> //套接字
#include <netinet/in.h>
#include <sys/un.h>
#include <net/if.h>
#include <netinet/udp.h>
#include <poll.h>

#define MAXBUF 1024
#define MAX 4096
#define SA struct sockaddr //通用地址结构用于地址转换
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define ERR                 \
    {                       \
        printf("error \n"); \
        exit(0);            \
    }
#define ID \
    printf("进程ID：%d\n", getpid());
#define OK printf("ok\n");
#define INET_ADDRSTRLEN 16
#define PCAP_ERRBUF_SIZE 1024

/*************function***************/
 
/**************网络相关************/
void sock_set_port(struct sockaddr *addr, u_short port);
//设置端口
int sock_get_port(struct sockaddr *addr, socklen_t len);
//获取端口
int sock_cmp_addr(const struct sockaddr *sa1, const struct sockaddr *sa2, socklen_t salen);
//比较两个地址结构
void tv_sub(struct timeval *out, struct timeval *in);
//时间相关
struct sockaddr *create_IP4(char *host, int port);
//返回套接字地址结构指针，注意此函数将申请内存
void create_IP4_2(char *host, int port, struct sockaddr *dest);
//初始化套接字地址结构，参数带入
int tcp_connect(struct sockaddr *desaddr);
// 创建 TCP 链接，返回套接字描述符
char *k_ntop(struct sockaddr *addr);
//返回 转换地址->字符串地址
struct addrinfo *host_serv(char *hostname, char *serv, int family, int socktype);
//返回   addrinfo结构

/********简单输出******/
void couts(char *str);
//输出字符串
void coutd(int x);
void space(int x,char a);
//输出x个字符串a;
void echo_array(void*a,int len,int type);
//循环输出数组元素  1为指针 2为长度 3为元素类型


 

/********** io复用*********/
void echo_1(int sockfd);
//使用    select
void echo_2(int sockfd);
//使用    poll
 
#endif
