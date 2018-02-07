

#include "mainv2.h"

/*******线程********/
 

class  pthreads
{ 
public: 
     
         void * data[MAXPTHREADS];     //线程相关信息指针

 virtual void display_ptr_info();
          
         int new_ptr(void*(*(int))(int),int port);
         int cancel_ptr(pthread_t);
};
/*  
*     记录线程ID 
*/


