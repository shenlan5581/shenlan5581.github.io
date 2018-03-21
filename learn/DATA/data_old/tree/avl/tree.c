//树的相关操作函数
#ifndef _TREE_C
#define _TREE_C

#include "tree.h"
#include "display_tree.h"

node make_empty(node t) // 释放树
{
  if (t != NULL)
  {
    make_empty(t->left);
    make_empty(t->right);
    free(t);
  }
  return NULL;
}

node find(int x, node t)
{
  if (x == t->element)
    return t;

  if (x < t->element)
    return find(x, t->left);
  else if (x > t->element)
    return find(x, t->right);
  else
    return t;
}
node insert(int x, node t, char *name)
{
  if (t == NULL)
  {
    t = malloc(sizeof(struct treenode));
    t->left = NULL;
    t->right = NULL;
    t->element = x;
    t->name = name;
    t->height = 0;
  }
  if (x < t->element)
    t->left = insert(x, t->left, name);
  if (height(t->left) - height(t->right) == 2) //判断该节点是否平衡
    {  if (x < t->left->element)                  //如果插入的是左边
        t = singlerotateleft(t);
        else
        t = doublerotateleft(t);
    }
  if (x > t->element)
    t->right = insert(x, t->right, name);
    if (height(t->right) - height(t->left) == 2)
    {if (x > t->right->element)                  //如果插入的是左边
      t = singlerotateright(t);
      else
      t = doublerotateright(t);
    }


  t->height = max(height(t->left), height(t->right)) + 1;
  return t;
}
node singlerotateleft(node t)
{ //单左旋
  node x;
  x = t->left;
  t->left = x->right;
  x->right = t;
  return x;
}
node singlerotateright(node t)
{ //单左旋
  node x;
  x = t->right;
  t->right = x->left;
  x->left = t;
  return x;
}

node doublerotateleft(node t)
{ //单左旋

  t->left = singlerotateright(t->left);

  return singlerotateleft(t);
}
node doublerotateright(node t)
{ //单左旋

  t->right = singlerotateleft(t->right);

  return singlerotateright(t);
}

void traverse(node tree)  
{
  node n;
  Q *p;

  if (tree == NULL)
  {
    cout("tree is empty\n");
    return;
  }
  en(tree); //根入队

  tra = NULL; //初始化 游标指针

  for (;;) //循环
  {
    // p = de();    //出队   //此处更改为 遍历队列
    p = tr();
    if (p == NULL) //队为空
    {
 
      break;
    }
    n = p->N;

    if (n == NULL)
      continue;

    if (n->left != NULL)
      en(n->left);
    if (n->right != NULL)
      en(n->right);
  }

  init_E();

}

void traverse1(node tree)
{
  if (tree != NULL)
  {
    printf("name:%s,key:%d   ", tree->name, tree->element);
  }
  if (tree->left != NULL)
  {
    printf("->L:%s \n", tree->left->name);
    traverse1(tree->left);
  }

  if (tree->right != NULL)
  {
    printf("->R:%s \n", tree->right->name);
    traverse1(tree->right);
  }
}

void traverse2(node tree)   //中序遍历
{
  if (tree == NULL)
     return ; 
       traverse2(tree->left);
       printf("  %s\n", tree->name);
       traverse2(tree->right);          
}
int height(node p)
{
  if (p == NULL)
    return -1;
  else
    return p->height;
}

#endif
