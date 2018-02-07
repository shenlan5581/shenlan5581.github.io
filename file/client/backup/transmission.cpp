
 
#include "transmission.h"
extern transmission *T;
extern path *P;
extern dir *D;
extern interaction *I;
extern file *F;
extern pth  *PTH;
extern char share_dir[MAXPATH];
extern char *server_addr;
 
transmission::transmission(int sockfd)
{
  destfd =sockfd;
} 
       
int transmission::send(char * buf,int len  )
{   
 //   cout<<"send to server:~~~~~"<<buf<<len<<endl;
    write(destfd,&len,4);   //长度
    write(destfd,buf,len);  //正文
 
return 0;
}
int  transmission::recv(char * buf, int *len)
{ 
    int rdlen;
    int n;
  //  cout<<"reading......\n";
    n = read(destfd,&rdlen,4);
    if(n != 4)
    { 
        cout<<"read len error\n";
        return -1;
    }
   
    n = read(destfd,buf,rdlen);
    if(n !=rdlen)
    {
        cout<<"read error\n";
        return -1;
    }
   
    else
    *len = n;
 //   cout<<"read len"<<n<<endl;
return 0;
}

dir::dir(transmission * ct,path *cp)
{
    t = ct;
    m_path = cp;
}
 
int dir::init()
{  
    memset(m_dir,0,sizeof(m_dir)); 
    char c[1024];
    memset(c,0,1024);
    strcat(c,"dir ");
    strcat(c,m_path->m_path);
  
    t->send(c,m_path->pathlen+4);
  
    t->recv(m_dir,&dirlen);               
 return 0;
}
int dir::display()  //显示文件名
{ 
 // write(1,m_dir,dirlen); 
   int i,x,z,w,f,maxlen;
   char *filename[MAXFILENAME];

        filename[0]=m_dir;
         x=1;
         maxlen =0;
         z=0;
      for(i = 1;i<dirlen+1;i++)
    {    z++;
         if(m_dir[i]=='\n')
            { 
              m_dir[i]='\0';
              filename[x]=&m_dir[i+1];
               if(maxlen<z)
                 maxlen = z;
                 z=0;
                 x++;               
            }           
      }
      struct winsize  size;
      ioctl(STDIN_FILENO,TIOCGWINSZ,(char *)&size);
      
    //  cout<<size.ws_col<<size.ws_row;
    
      int d;
      d = size.ws_col/(maxlen+2); 
      w=0;f=0;
      for(i=0 ;i<x ;i++ )
    {   
       if(strcmp(filename[i],".")==0||strcmp(filename[i],"..")==0)
        continue;
        f++; 
        w = maxlen-strlen(filename[i]);  
        cout<< filename[i] ;
        for(z=0;z<w+2;z++)
         cout<<" "<<flush;
         if(f==d)
         { 
           cout<<endl;f=0;
         }
    }
   
     
    write(1,"\n",1);
    return 0;
}
int dir::mkdir(char*cmd)
{    
    
     int i;
     char s[512];
     memset(s,0,512);
     i = strlen(cmd);
     cmd[i-1] = '\0';
 
    //  1目录名不能含有/ 
   
     if(cmd[6]=='/'&&cmd[7]!='\0') //  2直接使用路径 
         {
              strcpy(s,cmd);    
         }
         else
         { 
            if(strstr(cmd,"/") !=NULL)  //目录名不能含有/ 
           {cout<<"director name can't contain '/'"<<endl;   
             return -1;
            }
            strcat(s,"mkdir ");
            strcat(s,m_path->m_path);
            if(strcmp(m_path->m_path,"/")!=0)
              strcat(s,"/");
            strcat(s,cmd+6);
         }
 
    t->send(s,strlen(s));
    memset(s,0,512);
    t->recv(s,&i); 
    if(strcmp(s,"ok")!=0)
     {
      cout<<"make dir failed"<<endl;
      return-1;
     }


   return 0 ;  
}
int dir::rmdir(char*cmd)
{    
    
     int i;
     char s[512];
     memset(s,0,512);
     i = strlen(cmd);
     cmd[i-1] = '\0';
 
    //  1目录名不能含有/ 
   
     if(cmd[6]=='/'&&cmd[7]!='\0') //  2直接使用路径 
         {
              strcpy(s,cmd);    
         }
         else
         { 
            if(strstr(cmd,"/") !=NULL)  //目录名不能含有/ 
           {cout<<"director name can't contain '/'"<<endl;   
             return -1;
            }
            strcat(s,"rmdir ");
            strcat(s,m_path->m_path);
            if(strcmp(m_path->m_path,"/")!=0)
              strcat(s,"/");
            strcat(s,cmd+6);
         }
 
    t->send(s,strlen(s));
    memset(s,0,512);
    t->recv(s,&i); 
    if(strcmp(s,"ok")!=0)
     {
      cout<<"remove dir failed"<<endl;
      return-1;
     }


   return 0 ;  
}
path::path(transmission * _t)
{
t =_t;
     
}
char * path::changepath(char *cmd ,dir *dir )
{  
      int i;  
      i =strlen(cmd);
      cmd[i-1]='\0';
      
      if((i+pathlen)>512)
    {  cout<<"path too long"<<endl;
       goto b;
    }  
 
    if(strcmp(cmd ,"..")==0)        //返回上层目录
    {
         if(strcmp(m_path,"/")==0)
          {
            cout<<"Is already the root directory"<<endl;
           goto b;
          }
        else
        {
          for(i=pathlen;i>0;i--)
          {  
 
             if(m_path[i] == '/')
               {
               m_path[i] = '\0' ;
               goto b;   
               }    
               m_path[i] = '\0' ;           
           } 
        } 
     goto b;      
    } 
    if(strcmp(cmd,".")==0)      //当前目录
           goto b;
    if(strcmp(cmd,"/")==0||strcmp(cmd," ")==0
       ||strcmp(cmd,"\n")==0||strcmp(cmd,"\0")==0)      //返回根目录
    {
        memset(m_path,0,200);
        m_path[0] = '/';
          goto b;
    }
          
   dir->init();  
   if(cmd[0]=='/' && cmd[1] != '/')  //目录变更
     {   
          if(check(cmd)==0)
         { memset(m_path,0,1024);
          strcpy(m_path,cmd);
          goto b;
         }
         else
           return NULL;
           
     }
   
   if(strstr(dir->m_dir,cmd)==NULL)   //检测文件名是否在dir中
      {
        return NULL; 
      }
      else
    {
   
      if(strcmp(m_path,"/")==0)    //进入子目录 
        {   
            strcat(m_path,cmd);
            goto b;
        }   
         else
         {
         
            strcat(m_path,"/");   
            strcat(m_path,cmd);
            goto b;
         }
    }

  b:{
     pathlen = strlen(m_path);
     return m_path;
     }
}
 int  path::init()
 {  
    memset(m_path,0,1024);
    t->recv(m_path,&pathlen);
    return 0;
 } 
 int path::display()
{
    write(1,m_path,pathlen);
    cout<<endl;
    return 0 ;
}
 
int path::check(char *cmd)
{   
  
    char c[1024];
    int  r_len;
    memset(c,0,1024); 
    strcat(c,"dir ");
    strcat(c,cmd);
  
    t->send(c,strlen(cmd)+4);
    memset(c,0,1024); 
    t->recv(c,&r_len);   
   if(strcmp(c,"path open failed")==0)
     return -1;
     else
     return 0;

}
 
 
 int file::rm(char *cmd)
 {   
   
   char result[10];
   int  r;
   
     int i;  
      i =strlen(cmd);
      cmd[i-1]='\0';

  char request[512];
  memset(request,0,512);
  strcat(request,"rm ");
  strcat(request,P->m_path);
  strcat(request,"/");
  strcat(request,cmd+3);
  
   T->send(request,strlen(request));

   memset(result,0,10);
   T->recv(result,&r);
   if(strcmp(result,"ok") != 0)
     {
       cout<<"remove file failed"<<result<<endl;
     return -1;
     }
    
   return 0;
 }
   
 int file::download( )
    {
    // goto test;
      pthread_t tid; //线程ID
     char  result[256] ;
     char filename[MAXPATH];
     int  len; 
  
  /********发送请求文件********/
      memset(filename,0,512);
      complete_path(filename,I->command + 9);
      //补全路径 获取当前文件名

     char req_file[MAXPATH];  //请求的文件
      memset(req_file,0,MAXPATH);
      strcat(req_file,(char *)"download ");
      strcat(req_file,filename);

      memset(result,0,256);
     T->send(req_file,strlen(req_file));
     T->recv(result,&len);
 

 if( (strcmp(result,"111 exist")==0)||strcmp(result,"222 exist")==0)   //请求下载          
       {
           cout<<"file non exist"<<endl;
        return -1;
       }   
      else     
       {

    /********获取端口号和文件长度********/
 // cout<<*(int *)result<<"dd"<<*((unsigned *)(result+4));
 
        //本地文件名
      char  filename[MAXPATH];
      int   filefd;
 
        
     /********创建本地文件*****/
     for ( ;  ; )
  {
      memset(filename,0,MAXPATH);
      cout<<"[download]enter save file name:"<<flush;
      read(1,filename,MAXPATH);
      if( filename[0] !='/')       //默认路径
         {   
            filename[strlen(filename)-1]='\0';  
             char tmpname[128];
             strcpy(tmpname,filename);
             memset(filename,0,MAXPATH);
             strcat(filename,share_dir);
             strcat(filename,"/");
             strcat(filename,tmpname);
         }
      filefd = creat(filename, S_IRUSR|S_IWUSR);
    if(filefd <0 )
     {
         cout<<"file create failed try again"<<endl;
         continue; 
     }
        filefd = open(filename,O_WRONLY,S_IWUSR);
    if(filefd <0)
      {
         cout<<"file write failed try again"<<endl;
          continue; 
      }
    
       break;
  }
    ///parameter
       char *parameter ;
       parameter =(char *) malloc(sizeof(char)*512);
       *(int *)parameter = *(int *)result; //端口
       *(unsigned *)(parameter+4) = *((unsigned *)(result+4)); //长度
       *(int *)(parameter+8) = filefd; //file
       strcpy(parameter+12,filename);
 
        test:  
        int err ;
       err =   pthread_create(&tid, NULL, D_file,parameter); //带入当前对象
         if(err ==-1)
         cout<<"xian"<<endl;
        return 0;
       } 
    }
 
    void *file::D_file(void *p) //线程函数
    {    
     
        struct info *pth_info;

        pth_info = PTH->get_new_info();
       
        pthread_mutex_lock(&mutex);
        pth_info->tid = pthread_self();
        pthread_mutex_unlock(&mutex);
          // cout<<"sleep"<<endl;
           //sleep(1000);  
       
        //端口 长度 fd
      char * x  = (char *)p;
        int  port =*(int*)x; 
       pth_info->file_size =*(unsigned int*)(x+4);
       pth_info->filename  =x+12;
      
        int   filefd =*(int*)(x+8); 
        int   ex = 0;  
        int   fd;
        int   n;
        char  buf[FILEBUF];
        int   end=0;
 
 
     pthread_cleanup_push(atexit, NULL); //set return function
        
        fd = mk_socketfd(server_addr, port);
       if(fd   <0)
         { 
           end=1;
           return NULL; 
         }
    pth_info->curr_size =0;
      //传输

       
      pth_info->AC = "download";
     cout<<"downloading......"<<endl;
     gettimeofday(&pth_info->start,NULL);
       for( ; ; )
    {       
 
          gettimeofday(&pth_info->curr,NULL);
          n = read(fd,buf,FILEBUF);
        if(n == 0)
        {
          cout<<"server err"<<endl;  
          end = 1;
          break;
        }
        write(filefd,buf,n);
          pth_info->curr_size =pth_info->curr_size +n;
     if(pth_info->curr_size ==pth_info->file_size)
       break; 

      
    }
     
    close(fd);
    close(filefd);
     
    pth_info->tid =0;
    
    pthread_cleanup_pop(end); 
    if(end == 0)
   {
    cout <<"\n[message] file transmission finish ~~ "  <<pth_info->filename<<flush; 
   }
    free(p);
      return NULL;   
    }  
     
    void file::atexit(void *p) //线程结束时函数
    {
     cout <<"\n"<< "[message] file transmission failed"<<flush;
     write(0,"\n",1);
    }


int file::upload()
{   
    char * filename;
    int  filefd;
    char request[MAXFILENAME];
    char result[RESULTLEN];
 
    int  r_len;
    unsigned int filelen=0;

    filename = (I->command)+7;
    to_default_share(filename);//如果为局部路径则定位到默认共享路径
  
    //检测文件是否存在 ， 创建文件描述符
    struct stat fileinfo; //文件信息
   
     if( stat(filename,&fileinfo) == -1 )                     
     {
       cout<<"file open failed"<<endl;
       return -1;
     } 

     filefd = open(filename,O_RDONLY); //文件FD
  
     for( ; ; )    //输入要保存的文件名
      {                         //请求  4字节长度 文件名
        
        char  tmp[MAXFILENAME];
        memset(tmp,0,MAXFILENAME);
        memset(request,0,MAXFILENAME);  

        cout<<"Enter new file name:"<<flush;
        read(1,tmp,MAXFILENAME);
        if( tmp[0] !='/') //局部路径
          {  
            strcat(request,"upload ");
            strcat(request+11,"/");
            strcat(request+11,tmp);
          }
         else 
         {
          strcat(request,"upload ");
          strcat(request+11,tmp);
         }
         cout<<request<<endl;
         cout<<request+11<<endl;
       T->send(request,strlen(request+11)+11);
       T->recv(result,&r_len);  
       if(strcmp(result,"file create failed")==0)
        {
           cout<<result<<"   try again"<<endl;
           continue;
        }
        else
        break; 
      }
        unsigned int flen = fileinfo.st_size;
 
        int port = *(int*)result;
        pthread_t tid;
         
        char * parameter ;
           parameter =(char *)malloc(256);

             *(int*)parameter = port;
             *(int*)(parameter+4) = filefd;
             *(int*)(parameter+8) = flen;
             strcpy(parameter+12,filename);
          
   pthread_create(&tid, NULL,U_file,parameter); //带入当前对象
 
       
 
   return 0; 
}    
void * file::U_file(void * p)
{     
   int  newport,filefd,sockfd,fflen,n;
   struct info  *newinfo;
   char * parameter;
   char buf[FILEBUF];
   parameter= (char*)p;
   newinfo  = PTH->get_new_info();
   newinfo->tid = pthread_self();

    newport = *(int*)parameter;
    filefd  = *(int*)(parameter+4);
    fflen   = *(int*)(parameter+8);

    newinfo->file_size =fflen;
    newinfo->curr_size = 0;
    newinfo->filename  = parameter+12;
 sockfd  = mk_socketfd(server_addr, newport);
     newinfo->AC="upload";
 cout<<"[message] uploading"<<endl;
      gettimeofday(&newinfo->start,NULL);
           for(  ;  ; )
        {    
            n = read(filefd,buf,FILEBUF); 
           
            if( n == 0)
             break;
             newinfo->curr_size += n;
             gettimeofday(&newinfo->curr,NULL);
        write(sockfd,buf,n);

        }

    cout<<"[message] upload finish"<<endl;
        free(p);
        newinfo->tid =0;
        close(sockfd);
        close(filefd);
return NULL;
}  
