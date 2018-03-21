
/*
   散列表
   分离链接散列 
*/
#include <stdio.h>
int tablesize = 20;
typedef struct node * EL;
struct node {
   int   key;
   char *name;
   EL    next;
};
EL * init_table() {     
      EL *h;
      EL *l;
      h =(EL*) malloc(sizeof(EL)*tablesize); 
      l =h;
      int i;
      for(i = 0; i<tablesize;i++) {
         *h = NULL;
          h++;
      }
return l;  
}

int hash(int key) { 
return key;
}
int insert(int x,char *name,EL *b) {  
       EL  n;
       n  = *(b+x);
      if(n == NULL) {     
         n = malloc(sizeof(struct node));     
      n->key= x ;  
      n->name=name;
      *(b+x) = n;  
     } else {  
         EL  k ;
         k = malloc(sizeof(struct node ));  
         n->next = k;
        
         n = n->next;
         n->key= x ;  
         n->name=name; 
     }
return 0; 
}

EL find(int x,EL  *b) {
     EL n;
     n = *(b+x);
    if(n == NULL)
    return NULL;
  else 
      return n;     
}
