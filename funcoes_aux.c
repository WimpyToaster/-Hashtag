#include "funcoes_aux.h"
#include "Item.h"
#include "ArvoreBinaria.h"

void avalia_hash(char *token, int size_str)
{

	if (Total_Hashtags == 0)
	{
		Item primeira_hash = new_item(token, size_str);
	    global_h = NewTree(primeira_hash, NULL, NULL);
	    Total_Hashtags++;
	    Maior = global_h->item;
	}

	else
	{
		
		Item hash = new_item(token, size_str);

		link existe = search(global_h, hash);
		
		if(existe == NULL)
		{
			hash->count = 1;
			global_h = insert(global_h, hash);
			Total_Hashtags++;
			
			if(Maior->count == 1)
			{
				if(strcmp(Maior->tag, hash->tag) > 0)
					Maior = hash;
			}
		}
		
		else
		{
			existe->item->count++;

			if(existe->item->count > Maior->count)
				Maior = existe->item;

		}
	}
}
