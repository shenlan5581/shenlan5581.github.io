/*
图   通过数据 （V,E)构建图 （邻接表）
*/
#ifndef _main_c
#define _main_c

 #include "k.h"
 #include "graph.c"
 
int size  = 5;
int tablesize  =23;

int main()
{    //原始数据  v 顶点集合  e边集合
   char *v[5];
     v[0] = "mama";
     v[1] = "xingke";
     v[2] = "ji";
     v[3] = "yaoyao";
     v[4] = "dd";   
    int e[] = {0,1, 0,3, 1,2, 2,4, 3,2, 3,4,  4 ,1};  //关系集合 2个为一对

       couts( 
        "  mama ----------->xingke  \n"
        "   | 0            / 1  ^    \n"
        "   |       2     v     |    \n"
        "   |      yuxinji      |     \n"
        "   |     ^       \\     |     \n"
        "   v3   /         v  4 |    \n"
        "  yaoao----------->buding  \
        n"
        );
 
      G graph;    //图
 
      graph = malloc(sizeof(struct graph_table)*5);
      memset(graph,-1,sizeof(struct graph_table)*5);
      
     int i,a,b;

     for(i =0;i<14;i+=2)  //将顶点放入图中
     {      
            a = e[i];
            b = e[i+1];      
         insert(graph,a,b,size);    
     }
        

     for(i = 0; i<5 ;i++)
     {  // 此顺序为放入顺序
        printf("%d   %s\n",i,v[i] ) ; 
     }


     //打印邻接表
       G n;
       for( i =0;i<size;i++)
       {   n = &graph[i];
           printf("  %d %s-----> ", n->g_nomber,
          
            v[n->g_nomber]);
          for( ;  ;)  
          {   
              if( n->next!=NULL)
           {    n=n->next;   
            printf("  %s-----> ", 
            v[n->g_nomber]);
           }
           else 
           break;
        }
        printf("NULL\n");
       }
   
       graph[0].dist = 0;  //开始顶点
       unweight_breadth_fist(graph,5); 
 
     // 输出表
     for(i =0;i<5;i++)
     {   n =&graph[i];
        printf("%d  %d -> %d  %d  %d \n",
        i,n->g_nomber,
        n->know,n->dist,n->v);
     }


}
 

 

#endif