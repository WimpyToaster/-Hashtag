#include "Item.h"


Item new_item(char *tag, int size_str)
{
	Item new = (Item) malloc(sizeof(struct Hashtag));

	new->tag = (char*) malloc(sizeof(char)*size_str);
	strcpy(new->tag, tag);
	new->count = 1;

	return new;
}
