#ifndef  tree_c
#define  tree_c
#include  <string.h>
#include  <stdlib.h>
#include  "tree.h"





/* return a new node of root 
*/
node BT_Create_Root() {
    node root;		
		root = malloc(sizeof(struct treenode)); 
		int i;
    for(i=0;i<M;i++) {
			root->key[i]=-1;
			root->p.child = NULL;     
		}  
		return root;
}
/*ADT insert
*/
node BT_Insert(node prant,int key ,void *data) {  
     if(nude == NULL){

     }




if(key < n->key[0]) {
 	n->p[0] = btinsert(r->p[0],key,name);        
}
if(x > r->key[0]  &&  x<r->key[1]) {
	n->p[1] = BTinsert(r->p[1],key,name);        
}

if (x > r -> key[2] && x <r->key[3]) {
	n->p[2] = BTinsert(r->p[2],key,name);        
}
if (x > r -> key[3]) {  //4
	n->p[3] = BTinsert(r->p[3],key,name);        
}


}

leaf insert_leafnode(int x, leaf r,char *name) 
{   
	int i , s;
	for(i = 0; i<r->num ; i++)
	{  

		if( r->key[i] < x  )    
			continue;
		else     // find 
		{                
			for(s = r->num-1;  ;s--)
			{                   
				r->key[s+1] =r->key[s]; 
				strcpy(r->data[s+1],r->data[s]);   
				if(s == i)
					break;      
			}

		}  
		break;       
	}
	r->key[i] = x;
	r->data[i] = name;

	return r;
}

leaf init_leaf(leaf t)
{  
	t = malloc(sizeof(struct treenode));
	int i;
	for(i =0 ; i<M-1;i++)
	{  
		t->key[i] = -1;    
		t->data[i]  =NULL;              
	}

	t->num = 0;
	t->type = LEAF;
	return t;
}
#endif
