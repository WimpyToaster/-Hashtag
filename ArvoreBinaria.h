ifndef _ARVOREBINARIA_
#define _ARVOREBINARIA_

#include "Item.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	
  Item item; 
  int height;
  struct node *l; 
  struct node *r; 

} *link;


link NewTree(Item item, link l, link r);
link search(link h, Item v);
link insert(link h, Item item);
int height(link h);
link rotL(link h);
link rotR(link h);
link rotLR(link h);
link rotRL(link h);
int Balance(link h);
link AVLbalance(link h);
void free_tree(link h);

#endif
