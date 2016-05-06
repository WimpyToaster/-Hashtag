#ifndef _ITEM_
#define _ITEM_
#ifndef _stdlib_
#define _stdlib_ 

#include <stdlib.h> 
#include "ArvoreBinaria.c"

typedef struct node {
	
  Item item; 
  struct node *l; 
  struct node *r; 

} *link;
 
static link head = NULL; 

link NovaArvore(Item item, link l, link r);
link procura(link h, Item v);
link insere(link h, Item item);
int altura(link h);

#endif
#endif
