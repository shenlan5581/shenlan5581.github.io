#ifndef _graph_c
#define _graph_c

#include "k.h"
static int  order=0;
typedef struct hash  *H;
struct hash{    
	char * name;
	int    nomber;
};

typedef struct save  *S;   
struct save{    
	char * name;
	int    nomber;
};

typedef struct graph_table  *G;  
struct graph_table{
	int g_nomber;
	struct graph_table* next;
	int indegree;  //节点入度
	int outdegree;
};
int hash_function( char * str,int tablesize);
int find_no_from_hs(char *a,H table,int tablesize,S save) ;
int insert(G graph,int a,int b,int size);  

int hash_function( char * str,int tablesize)
{    
	int hashval = 0;

	hashval =(int )str[0];

	return hashval%tablesize;
}


int find_no_from_hs(char *a,H table,int tablesize,S save )
{
	int i ;
	H   p;
	i= hash_function(a,tablesize);
	p = &table[i];
	if(p->nomber == -1) {
	  p->name=a;
		p->nomber =order;
		save[order].name=a;
		save[order].nomber = order;
		order ++;
		return p->nomber;
	} else {
		return p->nomber;
    }
	// 如果a在列表中返回该点序号 负责
}
int insert(G graph,int a,int b,int size) 
{
	int i;G n;
	for(i = 0;i<size;i++)
	{   
		if( graph[i].g_nomber ==a)  //在头数组中找到
		{   
			n =&graph[i];
			n->outdegree++;

			graph[b].indegree++;
			while(n->next!=NULL) 
			{
				n = n->next;
			}
			n->next =malloc(sizeof(struct graph_table));
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
				n->next->g_nomber = b;
				n->next->next =NULL;
				n->outdegree++;
				graph[b].indegree++;
				return 0;
			}
	}
	return -1;
}
#endif
