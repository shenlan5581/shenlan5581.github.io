
#ifndef _queue_c
#define _queue_c

 #include <k.h>
 #include "queue.h"
 #include "../find_tree/tree.h"

void en(void * n) //添加到队尾
{
   /* if (n == NULL)
    {
        cout("入队错误\n");
        exit(-1);
    }*/
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

Q *de()   //没有free
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
Q *tr()         // 游标指针  初始化 每次返回下一个
{ 
  
   if(tra ==NULL)  //第一次
   { 
     tra =front;      //记录上次 位置
     return front;
   }
    else 
    { 
        tra = tra ->next;  //调用时查询下一个 
        if(tra ==NULL)     //碰到队队
        return NULL;
    }
   return tra;         
} 
void traverse_queue(Q * n) //遍历
{       
    if(n==NULL)
     return;
    node p ;
    p = n->N;
    printf("%s\n",p->name); 
    traverse_queue(n->next);
}


#endif