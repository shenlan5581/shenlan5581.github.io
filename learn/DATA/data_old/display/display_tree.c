


#ifndef    _display_tree_c
#define    _display_tree_c
#include "tree.h"
#include "display_tree.h"
void init_E()
{   L ali;     //next格式
   int n;
   node l;     //临时
   
   memset(&ali,0,sizeof(ali));
   // 根  初始化根 信息
      ali.NO = 1;
      l = de()->N;
      ali.p[0] =l;
      if(l->left!=NULL)
      ali.nfn[0] =  1;
      if(l->left!=NULL)
      ali.nfn[1] =  1;
      ali.po =1;
      ali.w = width*2;
       //输出 根节点 
       show(&ali); 
   for ( ; ; )
     {  
       get_lin(&ali);   // 创建本层
       ali.po +=1;   
       show(&ali);        // 显示
        if(front==NULL)
       break; 
     }
     space(width*2,'-');
     printf("\n");
}
int get_lin(L *l )
{   
     int sz ;  //将要读取的个数 
     int * nfn; //记录空节点
     int  i;
     Q *p ;
     node t;
     int  x=0;

     sz =l->NO*2;
     
     nfn = l->nfn;
  
 for(i=0;i<sz;i++)
 {    
     if(nfn[i]==1)
     { 
          p =de();  
      if(p ==NULL)
          { 
            l->p[i]=NULL;
            l->NO = i;
            over = 1;
            return -1;  
          }
           l->p[i] = t =p->N;
           free(p);  
     }else
     {
        l->p[i] =NULL;
     }
 }  
  l->NO = sz;
  
  return 1;
}
int show(L* l)
{ 
    int  spance;
    int i;
    spance = get_w(l->w );
    l->w =spance;
     for(i = 0 ;i<l->NO;i++)
     {   
        if(i ==0)
        {
            
        space(spance,' ');
        } 
        else 
        {  space(spance,' '); 
           space(spance+1,' '); 
        }     
          if( l->p[i]==NULL)
           {   
               if(over ==1)
                return 0;
          
             printf("*");            
           }else{
           printf("%s",l->p[i]->name      );             
           }
         
    }  
 
printf("\n");
    int x=0;
    memset(l->nfn,0,50);
     for(i=0;i<(l->NO) ;i++)   //构建下层节点信息
     {   
         if(l->p[i]!=NULL)
         { if(l->p[i]->left!=NULL)
          l->nfn[x] =1; 
          if(l->p[i]->right!=NULL)
          l->nfn[x+1] =1;          
         }
         x+=2;   
 }   
   
     memset(l->p,0,50);
     return 1;
}
int get_w(int n )
{    
    
   
  
       
   return  n/2;
   
}

#endif           
