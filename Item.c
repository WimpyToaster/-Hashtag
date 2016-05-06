#include <string.h>

#define eq(a,b) (strcmp(a->tag, b->tag) == 0)
#define less(a,b) (strcmp(a->tag, b->tag) < 0)
	
	
typedef struct Hashtag{
	
	int count;
	int height;
	char *tag;
	
}Item;
