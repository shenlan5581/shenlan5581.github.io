
#include "graph.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define new(type,size) calloc(size,sizeof(type))
/*给出图顶点个数初始化图*/
Graph * Init(int nums){
   Graph * new_graph =new(Graph,nums); 
   return new_graph;
}
int Insert(Graph* graph,int nums,int arc1 ,int arc2)  {
   if(graph == NULL) {  //init
      return -1;
   } else {   //insert
     int i = In_hard(graph,nums,arc1);
     if(i<0)return -1;     //full
     if(graph[i]==NULL){   // 
        graph[i] = new(struct graph_node,1);   

        graph[i]->nomber = arc1;
        graph[i]->next= new(struct graph_node,1);

        graph[i]->next->nomber = arc2; 
        graph[i]->next->next = NULL; 
     } else {              // exists
        Graph j = graph[i];
        while(j != NULL) {
             if(j->next==NULL)
               break;
              j = j->next;
        }
        j->next=new(struct graph_node,1);
        j->next->nomber=arc2;
        j->next->next=NULL;
     } 
 	}
	return 1;
}

int In_hard(Graph* graph ,int nums,int arc){
    int i;
    for(i=0;i<nums;i++) {
        if(graph[i]==NULL)   // not inside return new node
        return i; 
        if(graph[i]->nomber == arc)   //insede return nomber
        return i;
    }
     return -1;               // onther full
}

void display(Graph *G,int nums,char **vertex) {
	int i,j;
	 for(i=0;i<nums;i++) {
			Graph node = G[i];
			if(node == NULL) break;
				while(node != NULL) {
					printf("%d:%s->",node->nomber,vertex[node->nomber]);
          node = node->next;
				}
	 printf("NULL\n");
	 }
}

