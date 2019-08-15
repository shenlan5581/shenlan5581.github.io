/*
图   通过数据 （V,E)构建图 （邻接表）
*/
#ifndef _main_c
#define _main_c
#include "k.h"
#include "graph.c"
int size  = 5;
int tablesize  = 23;

int main()
{    //原始数据  v 顶点集合  e边集合
   char *v[5];
     v[0] = "mama";
     v[1] = "xingke";
     v[2] = "ji";
     v[3] = "yaoyao";
     v[4] = "dd";   
    int e[] = {0,1,0,3,1,2,3,2,2,4,3,4,4,1};  //关系集合 2个为一对

       couts( 
        "  mama ----------->xingke  \n"
        "   |              /   ^    \n"
        "   |             v    |    \n"
        "   |      yuxinji     |    \n"
        "   |     ^       \\    |    \n"
        "   v    /         v   |    \n"
        "  yaoao----------->buding  \n"
        );


    H table;    //哈希表
    S save ;    //存储编号所对应的指针
    G graph;    //图

      table = malloc(sizeof(struct hash)*23);
      memset(table,-1,sizeof(struct hash)*23);
      save  = malloc(sizeof(struct save)*size);
      memset(save,-1,sizeof(struct save)*size);
      graph = malloc(sizeof(struct graph_table)*5);
      memset(graph,-1,sizeof(struct graph_table)*5);
     int i,a,b;
     for(i =0;i<14;i+=2)  //将顶点放入图中
     {      
            a = e[i];
            b = e[i+1];      
            a= find_no_from_hs(v[a],table,tablesize,save);//返回序号 
            b= find_no_from_hs(v[b],table,tablesize,save);//返回序号 
            insert(graph,a,b,size);    
     }
     for(i = 0; i<5 ;i++)
     { 
        printf("%d   %s\n",save[i].nomber,save[i].name) ; 
     }
     //打印邻接表
       G n;
       for( i =0;i<size;i++)
       {   n = &graph[i];
           printf(" i%d->%do   %s-----> ", n->indegree+1,
           n->outdegree+1,
           save[n->g_nomber].name);
          for( ;  ;)  
          {   
              if( n->next!=NULL)
           {    n=n->next;   
            printf("  %s-----> ", 
            save[n->g_nomber].name);
           }
           else 
           break;
        }
        printf("NULL\n");
       }
}

#endif
