//队列
#ifndef _queue_h
#define _queue_h
typedef struct queue Q;
struct queue
{ //节点队列
        void * N;
        Q *next;
} * front, *rear ,*tra;
/*列队例程*/
void en(void *n); //入队
Q *de();         //出队
Q *tr();        // 游标指针 每调用一次返回列队中下个节点
void traverse_queue(Q *n);//遍历

 
#include "queue.c"

#endif