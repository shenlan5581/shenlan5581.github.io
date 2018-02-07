  


#include "fun.h"
extern transmission *T;
extern path *P;
extern dir *D;
extern interaction *I;
extern file *F;
extern char share_dir[MAXPATH];

char *ana_file_name(char *str) 
//获取字符串          返回 文件名
{

    return NULL;
}

char *complete_path(char *curpath, char *cmd) 
//获取字符串 如果为局部路径自动补全  //返回
{

     
    int i;
    i = strlen(cmd);
    cmd[i - 1] = '\0';
     
      //   完整路径
    if (cmd[0] == '/' && cmd[1] != '\0')  
       {
           memset(curpath, 0, MAXPATH); //更改当前路径
           strcpy(curpath, cmd);
       }
       else{
     
        //判断当前目录
       if (P->m_path[0] == '/' && P->m_path[1] != '\0') //不是根目录
       {    
            strcat(curpath, P->m_path);          
            strcat(curpath, "/");
            strcat(curpath, cmd);
     }else{   
        
         strcat(curpath, P->m_path); 
         strcat(curpath, cmd);
 

        }
     }
 
     
     return curpath;  
}

int mk_socketfd(char *addr, int port)
{
    int sockfd;
    struct sockaddr_in servaddr;
    int err, n, i;                            //错误测试码
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // 套接字
    //创建服务器地址
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, addr, &servaddr.sin_addr);
    //建立链接
    err = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (err != 0)
    {   
        cout << "[connect] can‘t  connect server"<<endl;
        return -1;
    } 
    else
    {
        cout << "[connect] connecting-->server"<<endl; //成功链接
        return sockfd;
    }
}
 

int is_exist(char*filename)//确认文件存在
{   
     cout<<"[is exset]"<<filename<<endl;
     char result[10 ] ;
     int  len;
      char req_file[MAXPATH];  //请求的文件
      memset(req_file,0,MAXPATH);
      strcat(req_file,(char *)"download ");
      strcat(req_file,filename);
      

     T->send(req_file,strlen(req_file));
     T->recv(result,&len);
   
     if(strcmp(result,"non exist")==0){

     return 0;
     }

else 
return -1;
}


void sig_for_pipe(int) 
{ 
   cout<<"server can't connect"<<endl;
}


void to_default_share(char *p) 
{   
   p[strlen(p)-1]='\0';   //清除换行符

    if( p[0] !='/')       //局部路径 定位到默认共享文件夹
    {   
        
        char tmpname[128];
        strcpy(tmpname,p);
        memset(p,0,MAXPATH);
        strcat(p,share_dir);
        strcat(p,"/");
        strcat(p,tmpname);
    }
}