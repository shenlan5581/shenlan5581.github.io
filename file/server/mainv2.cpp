

//?过多的全局变量
//？类行为所需要的数据1全局变量 2构造初始化 3函数传入
//？类行为输出      1 函数返回值 2指针做参数






/****mian***/
#include "mainv2.h"

/*全局变量*/
 
  confv2 *conf;
  pthread_mutex_t mutex;
  ports   P;                  
  pthreads  PTR;               //线程
 
 int main()
{ 
     conf = new  confbyfile ; 
     conf->init();
      
     net_socket  N;  
     N->creat_connect(conf->addr,conf->port); 
     
     while(1)
    {  
         N->accept();
         if(fork() == 0)
         {



         }

 
    } 
 
}