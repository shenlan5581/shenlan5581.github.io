
#ifndef    _display_tree_h
#define    _display_tree_h

#include "k.h"
#include "tree.h"
#include "../queue/queue.h"

int  width =30 ;      //屏幕宽度
int  position;  //位置
int  over=0;
typedef struct elemnet E;
struct element     //每个元素位置信息
{ 
     int floor;
     int n;
     int po;
     void  *p;
};

typedef struct nextlin L;
struct nextlin    //每个元素位置信息
{ 
     int NO;          //元素个数;
     int po;          
     int w;
     node p[50];
     int  nfn[50];    //记录空节点
     
 };
/*****function********/
void init_E();
int get_lin(L *l );
int show(L *l);
int get_w(int n );
#include "display_tree.c"
#endif