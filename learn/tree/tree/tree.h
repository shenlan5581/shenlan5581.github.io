#ifndef _TREE_H
#define _TREE_H



#define cout(X) printf("%s",X)

typedef struct treenode *node ;

#define CHILD 1
#define SIBLING 2 
#define ROOT 3

#define nextsibling sibling_._nextsibling
#define sibling sibling_._sibling
#define fistchild child_._fistchild
#define child child_._child

union child_node {
        node _fistchild;
        int _child;
};
union sibling_node {
        node _nextsibling;
        int _sibling;
};
struct treenode {
        char name[10];
        union child_node child_;
        union sibling_node sibling_;
};

//队列
typedef struct queue Q;
struct queue {
        node N;
        Q *next;
} * front, *rear;
/*列队例程*/
void en(node n); //入队
Q *de();         //出队

#define SIZE sizeof(struct treenode)
/*****全局变量*****/
int seek; //文件偏移量
 
/*****例程*****/
node get_node(node tree, char *name); //返回某个节点
node get_parent_node(node tree,char *name);                //返回节点的父节点
void traverse(node s);                //遍历节点(子节点，兄弟节点）
int create(node parent, const char *content, int X);
//创建节点  该函数将申请空间 请稍后释放
int free_node(node X);
void delete_node(node tree,char *name);
int save_tree(node tree, char *path);
//存储信息到硬盘
void save_node(int file);
//保存节点（递归）
void transformation(node node);
//转换节点 指针->偏移量
node  createfromfile(char *path);
//重建树
node  createnodefromfile(int file);
//重建树 节点
void operatorbycommand(node tree);
//执行命令

#endif
