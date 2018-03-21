
#include "k.h"

#include "tree.h"

#include "../queue/queue.h"
#include "display_tree.h"

int main()
{
   node t;
   t= NULL;
   t = insert(10,t,"ma");
       insert(9,t,"ke");
       insert(15,t,"yo");
       insert(6,t,"yu");
       insert(11,t,"bu");
       insert(8,t,"ch"); 
  
   traverse2(t);    
   traverse(t);
 




}