//树的相关操作函数
#ifndef _TREE_C
#define _TREE_C

 
#include "tree.h"
#include "main.h"

int create(node parent, const char *content, int X)
{
    if (parent == NULL && X != ROOT)
    {
        cout("未查找到相关节点\n");

        return -1;
    }

    switch (X)
    {
    case ROOT: //根节点
    {
        parent->fistchild = NULL;
        parent->nextsibling = NULL;
        strcpy(parent->name, content);
        break;
    }
    case CHILD: //子节点  创建子节点
    {
        if (parent->fistchild != NULL)
        {
            cout("the child of this node is not empty\n");
            return -1;
        }
        node new;
        new = malloc(sizeof(struct treenode));
        parent->fistchild = new;
        new->fistchild = NULL;
        new->nextsibling = NULL;
        strcpy(new->name, content);
        break;
    }
    case SIBLING:
    {
        if (parent->nextsibling != NULL)
        {
            cout("the sibling of this node is not empty\n");
            return -1;
        }
        node new;
        new = malloc(sizeof(struct treenode));
        parent->nextsibling = new;
        new->fistchild = NULL;
        new->nextsibling = NULL;
        strcpy(new->name, content);
        break;
    }
    }

    cout(" Successfu operation \n");
    return 0;
}
void delete_node(node tree, char *name)
{   
    if (strcmp(tree->name,name)==0)
      {
           free_node(tree);
      }
    //应该判断 root
    node parent;
    parent = get_parent_node(tree, name);
    
    if(parent ==NULL)
    cout("can not find node of tree\n");

   if(parent->fistchild !=NULL)
   {    
    if (strcmp((parent->fistchild)->name,name)==0)
    {   free_node(parent->fistchild);
        parent->fistchild = NULL;
        
    }
   }
   if(parent->nextsibling!=NULL)
    {  
     if (strcmp((parent->nextsibling)->name,name)==0)  
     {   
        free_node(parent->nextsibling);
        parent->nextsibling = NULL;
     }   
    }

  
}
int free_node(node N)
{   
    if (N == NULL)
    {
        
        return 0;
    }
    node next;
    next =N; 
     
     free_node(next->fistchild);
     free_node(next->nextsibling);
     free(N);
     cout("free\n");
     return 0;
}

node get_parent_node(node tree, char *name)
{ //无法判断根节点 返回某节点的父节点
    // 有返回值的 二叉递归函数
    node parent;      //记录父节点
    node test;        //测试节点
    node re;          //返回节点
    if (tree == NULL) //tree 为空 返回NULL
    {
        return NULL;
    }
    // 如何判断查找的节点为根节点？？？
    parent = tree;

    test = tree->fistchild; // 左节点
    if (test != NULL)
    {
        if (strcmp(test->name, name) == 0) //测试
            return parent;                 //子节点符合  返回
        re = get_parent_node(test, name);  //循环
        if (re != NULL)
            return re;
    }
    test = tree->nextsibling; // 右节点
    if (test != NULL)
    {
        if (strcmp(test->name, name) == 0) //测试
            return parent;                 //子节点符合  返回

        re = get_parent_node(tree->nextsibling, name); //循环
        if (re != NULL)
            return re;
    }
    else
        return NULL;
}
node get_node(node tree, char *name) //返回某个节点
{
    node node;
    if (tree == NULL)
    {
        return NULL;
    }
    if ((strcmp(tree->name, name)) == 0) //对比当前节点
    {
        return tree;
    }

    node = get_node(tree->nextsibling, name);
    if (node != NULL)
        return node;
    node = get_node(tree->fistchild, name);
    if (node != NULL)
        return node;
    else
        return NULL;
}

static int size = 0; //记录当前层级

void traverse(node s)
{

    int i;

    for (i = 0; i < size; i++) //打印当前层级空格
    {
        printf(" ");
    }
    printf("%s %d\n", s->name, size); //打印名字

    if (s->fistchild != NULL)
    {
        size += 4;
        traverse(s->fistchild);
    }

    if (s->nextsibling != NULL)
    {
        traverse(s->nextsibling);
    }
    else
    {
        size -= 4;
    }
}
int save_tree(node tree, char *path)
{
    int file;
    file = open(path, O_WRONLY);
    if (file < 0)
    {
        printf("file opened failed");
        exit(-1);
    }
    seek = 1; //初值
    en(tree);
    save_node(file); // 保存节点
    close(file);

    seek = 1;
    return 0;
}
void save_node(int file) //层序遍历
{
    while (1)
    {
        Q *parent = de();
        if (parent == NULL)
            break;
        node NN = parent->N;

        free(parent);
        if (NN->fistchild != NULL)
        {
            en(NN->fistchild);
        }
        if (NN->nextsibling != NULL)
        {
            en(NN->nextsibling);
        }
        transformation(NN); //转换指针
        write(file, NN->name, SIZE);
        //保存当前节点
        printf("name:%s child seek:%d    sibling seek%d\n", NN->name, NN->child, NN->sibling); //写出到终端
        free(NN);
    }
}
void en(node n) //添加到队尾
{
    if (n == NULL)
    {
        cout("入队错误\n");
        exit(-1);
    }
    Q *new = malloc(sizeof(Q));
    new->N = n;
    new->next = NULL;
    if (rear != NULL)
    {
        rear->next = new; //当前队尾指向new;
        rear = new;       //尾指针指向队尾
    }
    else
    {
        rear = new;
        front = new;
    }
}

Q *de()
{
    if (front == NULL)
        return NULL;

    Q *D;
    D = front;
    front = D->next;
    if (front == NULL)
        rear = front;
    return (D);
}
void transformation(node node)
{
    if (node == NULL)
    {
        cout("transformation ERROR\n");
        exit(-1);
    }

    if (node->fistchild != NULL)
    {
        node->child = seek;
        seek++;
    }
    else
        node->child = -1;

    if (node->nextsibling != NULL)
    {
        node->sibling = seek;
        seek++;
    }
    else
        node->sibling = -1;

    /* seek += 2;*/
}
node createfromfile(char *path)
{
    int file;
    node c_tree;
    file = open(path, O_RDONLY);
    if (file < 0)
    {
        cout("文件打开失败\n");
        exit(-1);
    }
    c_tree = createnodefromfile(file);
    return c_tree;
}
node createnodefromfile(int file) //前续遍历重建树
{
    int n;
    int l, r;
    node x;
    x = malloc(sizeof(struct treenode));

    n = read(file, x, SIZE);
    l = x->child;
    r = x->sibling;

    if (n < 0)
        return NULL;
    if (l != -1)
    {
        seek = l;
        lseek(file, seek * SIZE, SEEK_SET);
        x->fistchild = createnodefromfile(file);
    }
    else
    {
        x->fistchild = NULL;
    }
    if (x->sibling != -1)
    {
        seek = r;
        lseek(file, seek * SIZE, SEEK_SET);
        x->nextsibling = createnodefromfile(file);
    }
    else
    {
        x->nextsibling = NULL;
    }
    return x;
}
//重建树 节点

void operatorbycommand(node tree)
//执行命令
{
    char **p;
    int len;
    for (;;)
    {
        p = read_command(&len);

        if (strcmp(p[0], "create") == 0)
        /*创建指令
       * 
       *  格式  1 create 2"str" 3CHI or SIB 4where
       */
        {
            int x;
            if (strcmp(p[2], "CHILD") == 0)
                x = CHILD;
            if (strcmp(p[2], "SIBLING") == 0)
                x = SIBLING;
            create(get_node(tree, p[3]), p[1], x);
            goto free;
        }
        if (strcmp(p[0], "traverse") == 0) //遍历
        {
            size = 0;
            traverse(tree);
            goto free;
        }
        if (strcmp(p[0], "delete") == 0) //推出保存树
        {           
          delete_node(tree,p[1]);        
            goto free;
        }
        
        
        if (strcmp(p[0], "exit") == 0) //推出保存树
        {
            save_tree(tree, conf.savepath);
            exit(0);
        }
        if (strcmp(p[0], "search") == 0) //查找
        {
            if (strcmp(p[1], "parent") == 0) //父节点
            {
                if (strcmp(p[3], tree->name) == 0)
                {
                    cout("this  node is root of tree\n");
                    goto free;
                }
                else
                {
                    node par = get_parent_node(tree, p[3]);
                    if (par == NULL)
                    {
                        cout("can not find this node of tree");
                        goto free;
                    }
                    else
                    {
                        printf("parent name if:%s \n", par->name);
                        goto free;
                    }
                }
            }
        }
        printf("Invalid commandn\n");
        goto free;

    free:
    {
        // printf("free1 :%d \n",len);
        int i;
        for (i = 0; i < len; i++)
        {
            // printf("free2\n");
            free(p[i]);
        }

        continue;
    }
    }
}

#endif
