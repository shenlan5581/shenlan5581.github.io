//树相关声明   头文件
#ifndef _TREE_H
#define _TREE_H
 
/*****声明*****/
typedef struct treenode *node ;
 
 
struct treenode
{   char *name;
    int element;
    int height;
    node left;
    node right;  
};
 
/*****二叉查找树例程*****/
node make_empty(node t);  // 释放树
node find(int x,node t );  //根据X查找节点
node insert(int x,node s,char *name);//插入节点
int height(node p);  //返回一个高度

node singlerotateleft(node t);
node singlerotateright(node t);

node doublerotateleft(node t);
node doublerotateright(node t);

void traverse(node tree);  //遍历
void traverse1(node tree);  //前序遍历
void traverse2(node tree);  //中序遍历
#include "tree.c"
#endif
