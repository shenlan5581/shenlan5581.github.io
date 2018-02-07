
 
#include  "main.h"
  
 
/*******全局变量*******/
char *qs          = (char*) "xingke";
//奇怪的问题？？？？？？
char *server_addr =(char*) "192.168.1.109";
int  default_port = 9811;
int  default_sockfd;
pthread_mutex_t mutex;
 char   share_dir[MAXPATH];


transmission *T;             
path         *P;           
dir          *D;     
interaction  *I;
file         *F;
pth          *PTH;
//问题  信号处理函数只有一个int 参数如何通过处理函数获得进程数据



 /****************主函数**************/

int main(){
    char * usr_path = getenv("HOME");  
    memset(share_dir,0,MAXPATH);
    strcat(share_dir,usr_path);
    strcat(share_dir,"/share");
        
    if(mkdir(share_dir,S_IRUSR|S_IWUSR|S_IXUSR)==0)
    {
       cout<<"[create a shared folder" <<share_dir<<"]"<<endl;
           
    } 

    default_sockfd = mk_socketfd(server_addr,default_port);
  if(default_sockfd<0)
     return -1;
   
/***信号***/
 signal(SIGPIPE,sig_for_pipe); 


  T = new transmission(default_sockfd);
  P = new path(T);
  D = new dir(T, P);
  I = new interaction;
  F = new file ;
  PTH = new pth;
  P->init();

  for (;;)
  {
    I->updatacommand(P);   
    switch(I->mask)
  {
      case  0 :             //  cd
      {  
        if(P->changepath(I->command+3,D)==NULL) 
          cout<<"file name does exist\n";
        break;
      }
      case  1 :             //  get
       {   
        cout <<I->masklen<<endl;   
        break;
       }
      case  2 :             // 显示当前目录 ls
        {   
          D->init();       //更新当前目录
          D->display();
        break;
        }
      case  3:              //退出程序
            close(default_sockfd);
        return 0;
        
      case  4:              //创建目录
           D->mkdir(I->command);
        break;
      case  5:
           D->rmdir(I->command);
            break;
      case  6:
           F->rm(I->command);
            break;
      case  7:            
           F->download();
            break;
      case  8:               //info
            PTH->show_info(); 
  
           break; 
      case  9:
           F->upload();
           break;
      case -2:
        break;
      default:
        cout << "command error" << endl;
  }
 }

}

 
int getfile(char * P,int fd)
{

    int filelen=0;
    int n; 
    char fD[1000];
    int filefd;
 
     filefd = open(P,O_CREAT);
    if(filefd <0)
     {
         cout<<"file create failed";
         exit(0);
     }
 
    
    filefd = open(P,O_WRONLY);
    if(filefd <0)
    {
    cout<<"file write failed";
     exit(0);
    }
   cout<<"transimsion";
    for( ; ; )
    { 
      
       n = read(fd,fD,1000);
       write(filefd,fD,n);
       filelen = filelen + n;
    if(n == 0)
     break;
    }
   close( fd);   
  cout<<filelen<<endl;
 return 0;
}
  
  
 