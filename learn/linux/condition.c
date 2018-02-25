#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define WRITER  20
#define READER  20
#define MAXBUFLEN 1000000
#define TESTTIME  20
typedef struct bufer *Jnode;
struct bufer{
 const char  * value;  
 Jnode    next;
};
Jnode rear = NULL;
int   count = 0;

pthread_mutex_t  mutex;    
pthread_cond_t   RD;    
pthread_cond_t   WR;        

void *  Write( void  *buf);  //producer
void *  Read( void  *buf);   //consumer
void    in(const char* vlaue);
Jnode   out();

int main() 
{   
  pthread_t   tid; 
  pthread_mutex_init(&mutex,NULL);
  pthread_cond_init(&WR,NULL);
  pthread_cond_init(&RD,NULL);
  int i;
  for(i=0;i<WRITER;i++)
     pthread_create(&tid,NULL,Read,rear); 
	for(i=0;i<READER;i++)                      
     pthread_create(&tid,NULL,Write,rear);
  sleep(TESTTIME);   //wait exit 
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&RD);
  pthread_cond_destroy(&WR); 
  printf("%d",count);
  return 0; 
}

void * Read (void *buf)  
{   
  while(1) {
   pthread_mutex_lock(&mutex);
	 while(rear == NULL)       
        {      
         write(1,"rdempty",7);
         pthread_cond_wait(&RD,&mutex);   
        }    
						 Jnode node = out();  //如果读取的是满的 send
             free(node);
             write(1,"rd ",3);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&WR); //send signal  
  }   
  return NULL;
}

void * Write(void *buf)  
{  
  while(1) {
   pthread_mutex_lock(&mutex);
	 while(count == MAXBUFLEN)       
        {      
         pthread_cond_wait(&WR,&mutex);   
        } 
         in("hello,word");
          write(1,"wr",3);
         if (count == MAXBUFLEN) { 
           write(1,"full ",5);
         pthread_mutex_unlock(&mutex);
         pthread_cond_signal(&RD); //send signal
         continue; 
       }
         pthread_mutex_unlock(&mutex);
  }   
  return NULL;
} 
// queue
void in(const char * value) {
    Jnode node = malloc(sizeof(Jnode));
    node->value = value;

   if(rear == NULL){      //init
     Jnode end = malloc(sizeof(Jnode));
     end->value = NULL;
     end->next = node;
     node->next = end;
     rear = node ;
     count = 1;
    } else { 
    node->next = rear->next;
    rear->next = node;
    rear = node; 
    count++;
    }
}
Jnode out() { 
  if(rear == NULL) 
     return NULL;
       count--;
      Jnode node;
    if (rear->next->next == rear) { 
	     node = rear;
       free(rear->next);
       rear = NULL;
	  return node; 
     } else {
      node = rear->next->next;
      rear->next->next=node->next;
    return node;
		}
} 
