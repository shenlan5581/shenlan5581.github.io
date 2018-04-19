#ifndef QUEUE_H
#define QUEUE_H
/*
.c文件包含了 队列front,rear指针
只有唯一的一个队列
使用 1push 2pop
*/
typedef struct Queue* queue;
struct Queue {            
  void  *data;
  queue next;
};
void push(void *data);      
void *pop (); 
#endif
