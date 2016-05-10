#ifndef _ITEM_
#define _ITEM_

#include <string.h>
#include <stdlib.h>

#define eq(a,b) (strcmp(a->tag, b->tag) == 0)
#define less(a,b) (strcmp(a->tag, b->tag) < 0)
	
	
typedef struct Hashtag{
	
	int count;	
	char *tag;
	
}*Item;

Item new_item(char *tag, int size_str);

#endif
