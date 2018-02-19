// 相关函数

#ifndef _SER_C
#define _SER_C

#include "ser.h"
//********配置相关*********
void move_space(char *str)
{
  int i;
  for (i = 0; i < strlen(str); i++)
  {
    if (str[i] == ' ') //碰到空格
    {
      int ii;
      for (ii = i; ii < strlen(str); ii++)
      {
        str[ii] = str[ii + 1];
      }
      i -= 1;
    }
  }
}
void getkeyandvalue(char *str, char *key, char *value)
{
  int i;
  for (i = 0; i < strlen(str); i++)
  {
    if (str[i] == '=')
    {
      int ii;
      int x = 0;
      for (ii = 0; ii < i; ii++)
      {
        key[ii] = str[ii];
      }

      for (ii = i + 1; ii < strlen(str); ii++)
      {
        value[x] = str[ii];
        x++;
      }
      value[x - 1] = '\0'; // 去除最后的换行符
      break;
    }
  }
}
void read_line(int filefd, char *str)
{
  int n;
  int i;
  for (i = 0; i < 100; i++)
  {
    n = read(filefd, &str[i], 1);
    if (str[i] == '\n')
    {
      break;
    }
    if (n < 0)
    {
      str[i] = '\0';
      return;
    }
  }
}
void getcfg(char *path, char *p[])
//  获取路径名，返回键值数组 (二维数组）
{
  char buf[100];
  int i = 0;
  char a;
  int n = 1;
  int filefd;
  filefd = open(path, O_RDONLY);
  if (filefd < 0)
  {
    cout("读取路径失败");
    exit(0);
  }
  while (1)
  {
    memset(buf, 0, 100);
    read_line(filefd, buf); //读取字符

    if (buf[0] == '\0') //判断行末
    {
      close(filefd);
      p[i] = NULL;
      break;
    }
    move_space(buf); //去掉空格
    char key[50];
    char value[100];
    memset(key, 0, 50);
    memset(value, 0, 100);
    getkeyandvalue(buf, key, value); //分离键值对

    char *save_key = malloc(sizeof(key));
    char *save_value = malloc(sizeof(value));

    memset(save_key, 0, 50);
    memset(save_value, 0, 100);
    strcpy(save_key, key);
    strcpy(save_value, value);

    p[i] = save_key;
    p[i + 1] = save_value;
    i += 2;
  }
}

void init_cfg(struct _ser *_ser) //初始化
{
  char *re[20]; //此处申请10个地址空间存储参数

  getcfg("/home/k/learn/data/tree/conf.txt", re); //当前文件夹
  char **p = re;
  for (;;)
  {

    if ((strcmp(*p, "savepath") == 0))
    {
      strcpy(_ser->savepath, *(p + 1));
      break;
    }
    p += 2;
    if (*p == NULL)
      break;
  }
  int i = 0;
  for (;;) //释放申请内存空间
  {
    if (re[i] == NULL)
      break;
    else
    {
      free(re[i]);
      re[i] = NULL;
    }
    i++;
  }
}
char **analysis(char *buf)  //version one bug
{ /*动态创建了4个字符串
     *保存单词
    */
  
  char **p;
  char c;
  char *fi = malloc(25); //没有释放
  char *se = malloc(25);
  char *th = malloc(25);
  char *fo = malloc(25);
  memset(fi, 0, 25);
  memset(se, 0, 25);
  memset(th, 0, 25);
  memset(fo, 0, 25);
  char *ar[] = {fi, se, th, fo}; //该变量 在程序结束时释放掉所以 是个BUG
  p = ar;
  movespaceofhard(buf);

  int i, x, z;
  i = 0;
  z = 0;
  x = 0;
  for (; i < 50; i++)
  {
    if (z == 4)      //只有4个存储空间
    {  
      p = ar;
      return  p;
    }
    c = buf[i];
    if (c == '\0' && c == '\n')
    {
      p = ar;
      return p;
    }
    if (c == ' ')
      continue;
    if (c != ' ') /////////
    {
      for (; i < 50; i++) //小循环
      {
        if (buf[i] == '\0' || buf[i] == '\n') //到文件尾
        {
          p = ar;
          return p;
        }
        if (buf[i] == ' ')
        {
          z++;
          p++;
          x = 0;
          break;
        }
        if (buf[i] == '\0')
          break;

        (*p)[x] = buf[i];
        x++;
      } /////////////////////////////
    }
  }
}

char **create_command(char *buf,int * len) //version two
{                               
  char **p;
  char c;
  movespaceofhard(buf);
  char word[10][50];  //用二维数组存储
  int i, x, z;
  i = 0;
  z = 0;
  x = 0;
  for (; i < 50; i++)  //大循环
  {
    c = buf[i];
    if (c == '\0' || c == '\n')  //遇到文件尾
    {
      goto re;
    }
    if (c == ' ')     //遇到空格
      continue;
    if (c != ' ') /////////
    {
      for (; i < 50; i++) //小循环
      {  c = buf[i];
        if (c == '\0' || c== '\n') //到文件尾
        {
          word[z][x] ='\0';//此处在结束时添加\0
          goto re;
        }
        if (c == ' ')  //复制遇到空格
        {
          word[z][x] ='\0';//此处在结束时添加\0
          z++;     //x word数组 下标 +1
          x = 0;   //x word 下标 重置0
          break;  
        }
        word[z][x] = c;
        x++;     //x word 下标 +1
      } /////////////////////////////
    }
  }
 re: //函数返回
   {   
      char *array = malloc(sizeof(char *)*(z+1));
      memset(array,0,8*z+8);
      p =(char **)array;
      char **s;
      s = p;  //保存头指针
       for(i =0;i<(z+1);i++)
       {    
          char * rr = malloc(strlen(word[i]));
            memset(rr,0,strlen(word[i]));
            strcpy(rr ,word[i]); 
            *p =rr;
            p++;            
       }
  
     
    *len = z+1;
     return s;
   }
}
 
char ** read_command(int * cm_len) //读取命令
{
  /* 获取键入命令返回指针数组                           
  */

  char buf[50];
  int n;
  
  char ** p_command;
  
    int file = open("./command.txt", O_RDONLY);
    if (file < 0)
    {
      cout("file opened failed\n");
      return NULL;
    }
    memset(buf, 0, 50);
    n = read(0, buf, 50); //读取命令
    
   p_command= create_command(buf,cm_len);  //返回命令指针数组
    
     
     /*for(e=0 ;e<ar_len;e++) //回显输入
     {    
        printf("%s",*p);
        p++;
     }*/
     
     
    /****命令过滤******/
    if (p_command== NULL && n < 0)
    {
      cout("command error:read or analysis\n"); 
    }
  return p_command;
}

void movespaceofhard(char *buf)
{
  char c;
  int i, x;
  for (i = 0; i < sizeof(buf); i++)
  {
    c = buf[i];
    if (c == ' ')
      continue;
    else
      break;
  }
  x = 0;
  for (; i < 50; i++)
  {
    c = buf[i];
    if (c == '\0')
      break;
    buf[x] = buf[i];
    x++;
  }
}

#endif