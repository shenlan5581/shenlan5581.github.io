#ifndef _GRAPH_H
#define _GRAPH_H
#include <string.h>

/*     基本概念
组成信息 G = VE
边       arc
有向图   顶点有序 digraph
无向图   顶点无序
环  指   一条到其自身的路径
圈  指   两个顶点相互指向 a <-> b


char *vertex[5];     //V 代表顶点
     vertex[0] = "mama";
     vertex[1] = "xingke";
     vertex[2] = "yuxinji";
     vertex[3] = "yaoao";
     vertex[4] = "buding";   

int edge[] = {0,1,  0,3,
              1,2,
              2,4, 
              3,2   3,4
              4,1 };  //E  关系集合 2个为一对
 
 char* s = (
        "  mama------------>xingke  \n"
        "   | 0            / 1 ^    \n"
        "   |             v    |    \n"
        "   |      yuxinji     |    \n"
        "   |     ^  2    \\    |    \n"
        "   v 3  /         v 4 |    \n"
        "  yaoao----------->buding  \n"
        );
邻接表 表示法
 顶点             邻接的元素
--------+----------------------------------
 mama   | -> xingke   ->  yaoyao  {0-1,0-3}
--------+----------------------------------
 yaoyao | -> yuxinji  ->  buxing  {1-2,1-4}
--------+----------------------------------
 ... ...

*/
//基本邻接表单个顶点
#define GRAPH_SIZE
typedef struct graph_node  *Graph;  
struct graph_node{
	int     nomber;    //编号
	Graph   next;      //指向的节点 是（所有与该节点相连的节点） 
};
//通过边信息构建图
Graph *Init(int nums);
int   Insert(Graph* graph, int  nums,int arc1,int arc2);  
int   In_hard(Graph* graph ,int nums,int arc);


void display(Graph *G,int nums,char **vertex);
#endif
