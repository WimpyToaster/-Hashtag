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


/*
void radix_sort(Item *a, int vec_len, int M)
{   

	int i, j, cnt[M];
	Item *b = (Item*)malloc(sizeof(Item)*vec_len);
	
	for (j = 0; j < M; j++) 
		cnt[j] = 0;
		
	for (i = 0; i < vec_len; i++) 
		cnt[a[i].count+1]++;
	
	for (j = 1; j < M; j++) 
		cnt[j] += cnt[j-1];
	
	for (i = 0; i < vec_len; i++) 
		b[cnt[a[i].count]++] = a[i];
	
	for (i = 0; i < vec_len; i++)
	{
		a[i] = b[i];
		printf("count:%d tag:%s\n", a[i].count, a[i].tag);
	}
	
	free(b);
*/
