#ifndef _ITEM_
#define _ITEM_

#include <stdlib.h>

typedef struct node {
	
  Item item; 
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

#endif
