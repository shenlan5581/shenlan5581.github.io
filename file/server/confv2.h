

/*配置文件
*/ 
#include "main.h"

/*  配置类
*   初始化配置信息  创建共享文件夹
*/ 
class confv2  
{ 
public: 
    int      port;
    string   share_dir_path;
    int      max_pthreads;
    char     addr[13];  //ipv4
    
   virtual int init()=0;

private:
 
};

class confbyfile:public confv2
{
    virtual int init(){  };
};

class confbycommand:public confv2
{
    virtual int init(){  };
};