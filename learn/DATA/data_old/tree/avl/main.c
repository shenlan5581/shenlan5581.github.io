#include "tree.h"
#include "queue.h"
#include "display_tree.h"
int main()
{
   node t;   //初使化  
   t= NULL;
   t = insert(10,t,"ma");
   t = insert(5,t,"xi");
   t = insert(6,t,"yu");
   t = insert(12,t,"yo");
   t = insert(11,t,"bu");
   t = insert(9,t,"aa");
   t = insert(22,t,"1b");
   t = insert(33,t,"2b");
   traverse(t);  
   traverse2(t);    
}
