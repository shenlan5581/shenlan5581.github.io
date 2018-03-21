
#include "k.h"

#include "tree.h"

#include "../queue/queue.h"
#include "display_tree.h"

int main()
{
   node t; node newroot;
   t= NULL;
   t = insert(10,t,"ma");
       insert(9,t,"ke");
       insert(15,t,"yo");
       insert(6,t,"yu");
       insert(11,t,"bu");
       insert(8,t,"ch"); 
  
    traverse(t);
    newroot =   find(15,t);
    cout("find 15");
    traverse(newroot);

    newroot =   find(6,newroot);
    cout("find 6");
    traverse(newroot);

    newroot =   find(11,newroot);
    cout("find 11");
    traverse(newroot);

    newroot =   find(9,newroot);
    cout("find 9");
    traverse(newroot);

    traverse2(t);



}