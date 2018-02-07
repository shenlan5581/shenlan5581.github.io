

// 用于测试  获取 http 消息报文
 
 
#include "include.h"
 
int main()
{

    struct sockaddr addr;
    struct sockaddr accaddr;
    socklen_t acclen;

    int lsfd;
    int accfd;
    int n;
    int filefd;
    char msg[2000];

    struct sockaddr lsaddr;
    int port = 80;
    char *srcname = "192.168.1.103";
    lsfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    create_IP4_2(srcname, port, &lsaddr);

    if ((bind(lsfd, (SA *)&lsaddr, sizeof(lsaddr))) != 0)
    {
        printf("listen error1\n");
        exit(0);
    }

    if ((listen(lsfd, 20)) != 0) // 可能timewait
    {
        printf("listen error2\n");
    }
  for( ; ; )
  {  
    accfd = accept(lsfd, &accaddr, &acclen);

    n = read(accfd, msg, 2000);

    write(2, msg, n);

    printf("%d\n", n);

    filefd = open("/home/ki/share/a.html", O_RDONLY);
    if (filefd < 0)
        ERR
    n = read(filefd, msg, 2000);
    write(accfd, msg, n);
 
    close(accfd);
     
  }
     
}
