 
#include "interaction.h"  
 extern pth *PTH;
 
 interaction ::interaction() //构造
 {
   memset(command,0,100);
   cmdlen  = 0;
   mask    = -1;
 }; 
   
 
 int interaction::analysis(char *str,int len)
 {
     int  i,n ;
     char st[10];
     memset(st,0,10);
    for(i=0;i<len;i++) 
    {  
        if(str[i] == ' '||str[i] == '\n')
        break ;
        st[i] = str[i];
    } 
    masklen = i+1;

     if(strcmp(st,"cd")   == 0)
       return 0;
     if(strcmp(st,"get")  == 0)
       return 1;
     if(strcmp(st,"ls")  == 0)
       return 2;    
     if(strcmp(st,"exit") == 0)
       return 3;  
     if(strcmp(st,"mkdir")==0)
       return 4;
     if(strcmp(st,"\0")==0||strcmp(st,"\n")== 0)
       return -2;
     if(strcmp(st,"rmdir")==0)
       return 5;
     if(strcmp(st,"rm")==0)
       return 6;
     if ( strcmp(st, "download")==0) //下载
       return 7;
     if(  strcmp(st,"info")==0)     //进程信息
       return 8;  
     if(strcmp(st,"upload")==0)
       return 9;
   else  
   return -1; 
 }
 
 void interaction::updatacommand(path *_path)
 {  
    memset(command,0,512);
    cout<<_path->m_path;
    cout<<"$ :"<<flush;
    cmdlen = read(1,command,512);   
    mask   = analysis(command,cmdlen);
  
 }


/*****pth***/
pth::pth() 
{
  memset(AR,0,sizeof(AR));
}
  
int pth::show_info()
{    
    long  double a,b;
          int times;  
     
      for(int i=0;i<MAXPTHREAD;i++) 
          { 
           if(PTH->AR[i].tid !=0)
             {                 
          cout<<PTH->AR[i].AC;
          times =PTH->AR[i].curr.tv_sec- PTH->AR[i].start.tv_sec;//已用时间         
          a =( long  double)PTH->AR[i].file_size;
          b =( long  double)PTH->AR[i].curr_size;
          cout.precision(2); 
          cout<<i<< "~[info] filename:"<<PTH->AR[i].filename<<"   "; //文件名
          cout<<  "time:"<<times;
          cout<<"s    "<<b/a*100<<"%     ";
          cout <<setiosflags(ios::fixed);
          cout <<setprecision(2);
          cout<<b/times/1024/1024<<"M/s      ";
         
          cout<<"filezise:  "<<a/1000/1000<<"M"<<endl;    
             } 
          }
    return 0;
}     
struct info*  pth:: get_new_info()
{


      for(int i=0;i<MAXPTHREAD;i++) 
          { 
           if(PTH->AR[i].tid ==0)
            return &PTH->AR[i];
          }
    return 0;
 
  }
  

 