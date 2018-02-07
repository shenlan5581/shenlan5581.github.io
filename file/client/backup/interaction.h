/******交互******/
#ifndef     _interaction_h
#define     _interaction_h
 
#include "main.h"
using namespace std;
class path; 

/*交互
×   读取命令行请求
×   处理 
*/
class interaction  //包含传输对象 T 
{
public:
   char  command[512];          
   int   cmdlen;               
   int   masklen;           
   int   mask;                 //请求数字码

           interaction();                   
      void updatacommand(path * _path);  //获取命令
private:
      int  analysis(char *str,int len); //解析并返回命令码（扩展）
 };
  
/*线程信息结构
*   记录线程信息
*   及公共数据
*/
struct info
{ 
    pthread_t  tid;       
    char  *    filename;       //操作文件名
    string AC;  
    struct timeval start;      //开始时间
    struct timeval curr;       //当前时间

    unsigned int file_size ;     
    unsigned int curr_size ;   
  };


 /*线程
 *    记录线程信息
 *    分配新的线程结构   
 */ 
 class pth      
 {
public:
     struct info  AR[MAXPTHREAD];        
     
     pth();
     int show_info();
     struct info * get_new_info();//返回一个空的结构指针
}; 

 
 

  #endif