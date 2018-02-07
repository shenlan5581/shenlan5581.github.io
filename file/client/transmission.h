
#ifndef   _transmission_h
#define   _transmission_h  

#include "main.h"
 
  
/********传输层******/
  
extern pthread_mutex_t mutex;
class  path;
class  dir;
class  interaction;


/*传输
*   需求一个已连接文件描述符
*   接受和发送命令行
*
*/
class  transmission    
{ 
public:   
     int   destfd;
     
    transmission(int sockfd);
int send(char * buf , int   len);    
int recv(char * buf , int  *len);  //返回长度
}; 

 /*目录
 *   需求 传输 路径指针
 *   init()据当前路径m_path 初始化目录
 *   创建及删除目录 
 *   display;
 */  
 class dir
 {  
 public:
    char           m_dir[MAXDIRLEN];        
    int            dirlen ;
    transmission  *t;     
    path          *m_path;   //current path

         dir(transmission *ct,path *cp);
    int  init();         
    int  display();           //显示当期那路径
    int  mkdir(char *cmd);   
    int  rmdir(char *cmd); 
};

/*路径
*    需求 传输指针
*    存储路径
*    初始化 显示 检查
*/
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
   int  check(char *);
 
private:

};

/*文件
*   文件相关操作
*   下载（多任务）
*   上传（多任务）
*/
class file
{
public:
 
 
    int rm(char *cmd);     
    int download();         
    int upload(); 
private:
  static void  atexit(void *);
  static void *D_file(void *);  
  static void *U_file(void *);  
}; 
   
#endif

 