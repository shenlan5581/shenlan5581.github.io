
#ifndef _fun_h
#define _fun_h
/*****公共函数*******/
 #include "main.h" 
  
char *ana_file_name(char *str);
//获取字符串 返回 文件名

char *complete_path(char *curpath, char *cmd);
//获取字符串 如果为局部路径  补全路径

int mk_socketfd(char *addr, int port);
//创建连接 返回描述符 

int is_exist(char*filename);//确认文件存在
  
void sig_for_pipe(int);
  //SIGPIPE  信号处理函数

void to_default_share(char *);
// 获取路径如果局部路径则定位到默认共享文件夹
 
#endif 