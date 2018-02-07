#include <stdio.h>
#include <netdb.h> 
#include <stdlib.h>
#include <string.h>
#include <pthread.h>  //线程
 

void  * fun(void * a)
{
  printf(" pthread\n");

}

 int
 main()
 {
  pthread_t   tid ;

  pthread_create(&tid,NULL,fun,NULL);
 sleep(3);

return 0;
 }
