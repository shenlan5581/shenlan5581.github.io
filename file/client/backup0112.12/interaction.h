/******交互******/
#ifndef     _interaction_h
#define     _interaction_h


#include "main.h"
  
  
using namespace std;
class path; 
 
class interaction  //包含传输对象 T 
{
public:
   char  command[512];         //获取的命令
   int   cmdlen;               //命令长度
   int   masklen;           
   int   mask;                    //请求码

           interaction();                   
      void updatacommand(path * _path);  //获取命令
private:
      int  analysis(char *str,int len); //解析  并返回 命令码  （扩展）
    //  int  test();
};
struct info
{ 
    pthread_t  tid;
    char  *    filename;
    string AC;
    struct timeval start;
    struct timeval curr;
  
    unsigned int file_size ;
    unsigned int curr_size ;
};
class pth      
 {
public:
     struct info  AR[MAXPTHREAD];        
     
     pth();
     int en(pthread_t);
     int de(pthread_t);
     int show_info();
     struct info * get_new_info();//返回一个空的结构
}; 

 
  #endif