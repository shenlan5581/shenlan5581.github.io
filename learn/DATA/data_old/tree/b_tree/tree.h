/*
根 叶节点 子节点的 儿子数在 2~M 之间
除根节点 非叶节点 的儿子数 在 m/2 ~  M  之间
叶节点深度相同
2种节点类型
  1 内部节点
  2 叶节点 
                    (内部节点少用了一个关键字)
                     p 5 p null p 
                    /    (内部节点时指向子节点）
                   /
                  /
                 / 
              2 3 4 (叶节点时 key 的指针指向数据）   
              p p p

阶是固定常数
为子儿子数的最大个数 
*/
#ifndef  B_TEEE_H
#define  B_TEEE_H

#define  M    4   
#define  leaf   true
#define  inner  false 
typedef struct treenode * node;  // node
typedef struct treenode * leaf;  // leaf 
struct treenode {
   union p {                  //该联合体1叶节点时为数据指针 2 内部节点时为儿子指针
    void * data;
    node * child;
  };
      int   key[M]; 
      int   nums;	 
      bool  type;    //leaf or inner
};

// ADT
node Create_Root();             
node Insert(node root,int key,void* data); 
node Remove(int key,node x);		

#endif
