#ifndef _graph_c
#define _graph_c

#include "k.h"
 


typedef int vertex;

  
typedef struct graph_table  *G;  
struct graph_table{
    int g_nomber;
    struct graph_table* next; 
    int   know;
    int   dist;
    vertex   v;
};
 
 
int insert(G graph,int a,int b,int size);  
 
 
int insert(G graph,int a,int b,int size) 
{
      int i;G n;
 
      for(i = 0;i<size;i++)
      {   
          if( graph[i].g_nomber ==a)  //在头数组中找到
          {   
               n =&graph[i];

 

                while(n->next!=NULL) 
              {
                n = n->next;
              }
             n->next =malloc(sizeof(struct graph_table));
             memset(n->next,-1,sizeof(struct graph_table));
             n->next->g_nomber = b;
             n->next->next =NULL;
           
            
             return 0;
          }  
          else 
           if(graph[i].g_nomber ==-1||graph[i].g_nomber>5
              ||graph[i].g_nomber<-1 )
           {   
             n =    &graph[i];
             n->g_nomber = a;
             n->next =malloc(sizeof(struct graph_table));
             memset(n->next,-1,sizeof(struct graph_table));
             n->next->g_nomber = b;
             n->next->next =NULL;
 
             return 0;

           }
      }
  return -1;
}
int unweight_breadth_fist(G t,int len){
 
     int currdist;     //现在距离
     G v,w;       //
     int i ,j;

      for(currdist = 0;currdist<4;currdist ++)
      {  
            for(i=0;i<len ;i++) 
        {    w =  v = &t[i] ;
             if(v->know==-1&&v->dist ==currdist)
             {
                v->know =1; 
                
               while(w->next!=NULL)
                {  w = w->next;
                   if(t[w->g_nomber].dist== -1)
                   {                       
                    w->dist =currdist+1;   
                    t[w->g_nomber].dist = currdist+1;  
                    w->v  =i;
                    t[w->g_nomber].v= i;  
                   }
                }
             }
        }       
      }
}


#endif