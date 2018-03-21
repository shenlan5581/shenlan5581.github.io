#include <stdlib.h>
#include <string.h>
#include "queue.h"
queue front =NULL;
queue rear  =NULL;
void push(void * data) {
    queue new = malloc(sizeof(struct Queue));
    new->data = data;
    new->next = NULL;
    if (rear != NULL) {
        rear->next = new;
        rear = new;    
    } else {
        rear = new;
        front = new;
    }
}
void *pop() {
if (front == NULL)
   return NULL;
queue pop;
pop = front;
front = pop->next;
if (front == NULL)
    rear = front;
 void * ret;
 ret=pop->data;
        free(pop);
return (ret);
}
