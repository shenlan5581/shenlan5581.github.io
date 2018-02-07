
 
#include "mainv2.h"

/*******传输*******/ 
extern confv2 *conf;

class tra  //请求 响应  传输
{
public: 
    int  netfd;         
    
    tra(int netfd);
    int  send(char *,int len);
    int  recv(char *,int lne);
};


class  net_socket
{
public:
    int            sock_fd;
    sockaddr_in    cliaddr;
    socklen_t      cliaddrlen;  
    
    int creat_connect(int port,char* addr); 
    int accept();

};//创建套接字等待连接 当连接建立 返回描述符


class  ports  //当需要新链接时分配端口
{
public:   
    int   ports[conf->maxports];
   
    int   get_port();  
    int   free_port();
};


 