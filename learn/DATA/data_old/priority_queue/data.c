/* priority
   堆 优先队列
   二叉堆
*/

#include "k.h"

typedef struct  priority_queue *Q;
 
struct  priority_queue{

 int  size;      //当前大小
 int  capacity;  //总大小
 int  *keys;   //元素指针
};

Q init(int max)
{  
     Q h;
     h = malloc(sizeof(struct priority_queue));
         
     h->keys = malloc(sizeof(int) *max);
     h->capacity = max;
     h->size = 0;
     return h;
}

void insert(int key,Q t)
{ 
     int i ;

     for( i= ++t->size;t->keys[i/2]>key;i/=2)
       t->keys[i] = t->keys[i/2];
    t->keys[i] = key;

}

int deletemin(Q h)
{
     int i ,child;
     int min,last;

     min = h->keys[1];
     last = h->keys[h->size--];
  
     for( i = 1;i*2<h->size;i =child)
    {
            child = i*2;
      if( child !=h->size && h->keys[child+1]<h->keys[child])
          child ++;
        //找到较小的孩子
      if(last > h->keys[child]) //最低层 last 肯定比其父结点大
        h->keys[i] = h->keys[child];
      else 
        break;
    }
    h->keys[i] = last;
    return min;
        
}