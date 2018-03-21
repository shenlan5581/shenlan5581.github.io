//树相关声明   头文件
#ifndef _TREE_H
#define _TREE_H
 
/*****声明*****/
typedef struct treenode *node ;
 
 
struct treenode
{   char *name;
    int element;
    node left;
    node right;  
};
 
/*****二叉查找树例程*****/
node make_empty(node t);  // 释放树
node find(int x,node t );  //根据X查找节点
node insert(int x,node s,char *name);//插入节点
 




#include "tree.c"
#endif