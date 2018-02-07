
#ifndef   _transmission_h
#define   _transmission_h  

#include "main.h"
 
  
/********传输层******/
  
extern pthread_mutex_t mutex;
class  path;
class  dir;
class  interaction;

class  transmission     //初始化获取fd  定义接受  发送两个操作
{ 
public: 
  
     int   cfd;
     
    transmission(int sockfd);
int send(char * buf , int   len);    
int recv(char * buf , int  *len);  //返回长度

}; 
 /////// 目录///////
 class dir
 {  
 public:
    char m_dir[1024];           //目录缓冲区
    int  dirlen ;
    transmission *t;     
    path  *m_path;

    dir(transmission *ct,path *cp);
 
    int  init();
    int  display();
    int  mkdir(char *cmd);
    int  rmdir(char *cmd);
 };
//////路径//////
class  path 
{
public:
   char   m_path[1024];                   //updata get path
   int    pathlen;
   transmission *t;
   
   path(transmission *_t );
   char *changepath(char *cmd,dir * dir);//根据命令返回一个新的目录
   int  init();
   int  display();
   int  check(char *cmd);
private:
 
  
};
  
 
class file
{
public:
 
    int rm(char *cmd);     //移除文件
    int download();        //下载（线程）
    int upload(); 
private:
  static void atexit(void *p);
  static void *D_file(void *); // 下载线程函数
  static void *U_file(void *);
  
}; 
   
#endif

 