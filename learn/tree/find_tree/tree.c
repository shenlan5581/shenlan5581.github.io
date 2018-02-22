//树的相关操作函数
#ifndef _TREE_C
#define _TREE_C

 
 #include "tree.h"
 #include "k.h"
 #include "../queue/queue.h"
 #include "display_tree.h"

node  make_empty(node t)   // 释放树
{  
      if(t !=NULL)
       {
        make_empty(t->left);
        make_empty(t->right); 
        free(t);
       }
    return NULL;
}
    

node find(int x,node t)
{     
    if(x==t->element)
    return t;
    
    if(x<t->element)
      return find(x,t->left);
    else if(x>t->element)
      return find(x,t->right);
      else return t;
}
node insert(int x,node s,char *name)
{
   if(s == NULL)
   {  
          s = malloc(sizeof(struct treenode));
          s->left = NULL;
          s->right =NULL;
          s->element = x;
          s->name = name;
   } 
 
    if(x<s->element)
         s->left = insert(x,s->left,name);
    if(x>s->element)
         s->right = insert(x,s->right,name);
  
 return s;

}
 
 
void traverse(node tree)
{  
  node  n;  
  Q     *p;
 
 if(tree ==NULL)
       { cout("tree is empty\n");
        return;
       }   
        en(tree);  //根入队
        
       tra = NULL;//初始化 游标指针

    for( ; ; )       //循环
  {          
          // p = de();    //出队   //此处更改为 遍历队列
           p = tr();
          if( p == NULL)   //队为空
           { 
             cout("queue is empty\n");
             break;
           }
             n = p->N;
 
            if(n ==NULL)
             continue;
       
             if(n->left != NULL)         
                en(n->left);                
             if(n->right != NULL)
               en(n->right);        
    
  }
   
   init_E();
}  


void traverse2(node tree)
{
    if(tree !=NULL)
      {    
        printf("name:%s,key:%d   ",tree->name,tree->element);
      }
     if(tree->left !=NULL)
      {  cout("left<~");
        traverse2(tree->left);
      }
      
      if(tree->right !=NULL)
     { cout("right<~");
     traverse2(tree->right);
    }
}



#endif
