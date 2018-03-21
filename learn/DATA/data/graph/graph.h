#ifndef _GRAPH_H
#define _GRAPH_H


typedef struct graph_node  *Graph;  
struct graph_node{
	int     id;        //id
	Graph   next;      //adjacent  list
};
Graph Load(Graph graph,int *edge,int vertex_size,int nums);

//------------------------------------------

/*
拓扑排序(必须有向无圈图)
*/
void Top_Sort(Graph graph,int *edge,int vertex,int nums);
// 广度搜索
void BFS (Graph graph,int s,int vertex);



//-------------------------------------------
//display
void display(Graph G,int vertex_size,char **vertex);
#endif
