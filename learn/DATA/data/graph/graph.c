#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

Graph Load(Graph graph,int *edge,int vertex_size,int nums) {
     Graph G =calloc(vertex_size,sizeof(struct graph_node));
     Graph x;
     int i,u,v;
     for(i=0;i<vertex_size;i++)  //hard
         G[i].id = i;
     for(i=0;i<nums;i+=2) {      //adjacent list
         u = edge[i];
         v = edge[i+1];    
         x =&G[u];
         while(x->next != NULL) {              //find last node
            x=x->next; 
         }
            x->next = calloc(1,sizeof(struct graph_node));
            x->next->id = v;          
            x->next->next= NULL;
     }
return G;
}

//-------------------------------------------------------------
//Top_sert
void Top_Sort(Graph graph,int *edge,int vertex,int nums) {
     int indegree[vertex];
     int topnum[nums/2];
     int i,u,v;
     Graph x;
//记录节点入度
     for(i = 0;i<vertex;i++)
        indegree[i]=0;
     for(i=1;i<nums;i+=2) {
         v = edge[i];
         indegree[v]++; 
     }
//零节点入队
     for(i=0;i<vertex;i++) {
        if(indegree[i]==0) { 
          push(&graph[i]);        
        }
     }    
//排序
   i=0;
   while(1) {
      x = pop();
      if(x == NULL)break;
      topnum[i++]=x->id;
      printf("join:%d  ",x->id);
      while(x!=NULL) {
           indegree[x->id]--;
           if(indegree[x->id]==0) {
           push(&graph[x->id]);
           printf("push :%d  ",x->id);
           }
           x = x->next;
      }
   }
printf("\n");
   if(i!=vertex ) {
     printf("grpah has a cycle\n");
     return;
   }
//display
   for(i=0;i<vertex;i++) {
     printf("%d->",topnum[i]);
   }
   printf("\n");
}
// 广度优先 最小路径 
void BFS (Graph graph,int s,int vertex) {
 Graph i,j;
 int   x;
 struct INFO {     //info
      int known; 
      int dist;
      int path;   
 };
 struct INFO info[vertex];
 memset(info,-1,sizeof(info)); //初始状态 几点未知
 info[s].dist =0;
 push(&graph[s]);
 while(1) {
    i = pop();           //出队
    if (i == NULL) 
       break;
    j = i->next;
    while(j != NULL) {
       if(info[j->id].dist == -1) {//##只有节点未知（必须判断）
          //如果不加判断则会重复入队
          info[j->id].dist =info[i->id].dist+1;
          //路径长度+1;
          info[j->id].path = i->id;
          //记录 路径
          push(&graph[j->id]);
          //将已知节点入队
       }
       j = j->next;
    }   
  }
 printf("BFS\n");
   for(x=0;x<vertex;x++) {
     printf("(%d)->%d:%d  ",x,info[x].path,info[x].dist);
   }
   printf("\n");
}

void dijkstra(Graph,int vertex_size,int start) {
#define NotAVertex(-1);
// 标数结构
typedef struct TalbeEntry Table[vertex_size];
 struct TableEntry {
        Graph header; 
        int   known;
        int   dist;
        int   path;
 };
// 初始化表
 Table T; int i,j;
 for(i=0;i<vertex_size;i++) {
     T[i].known = -1;
     T[i].dist = -1;
     T[i].path = -1;
    }
   T[start].dist = 0;

int v,w ;
    for( ; ;) {
    v = 







}
//------------------------------------------------------------------------------
void display(Graph G,int vertex_size,char **vertex) {
     int i; 
     Graph node;   
     for(i=0;i<vertex_size;i++){
    	  node = &G[i];
				while(node != NULL) {
					printf("(%d)%s->",node->id,vertex[node->id]);
          node = node->next;
				}
      printf("NULL\n");
	 }
}

