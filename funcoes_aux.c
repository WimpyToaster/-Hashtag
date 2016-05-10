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
	    insert_vec_ord(primeira_hash);
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
			insert_vec_ord(hash);
			
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

/* para chamar: radix_sort(vec_ord, Total_Hashtags, Maior->count) 
void radix_sort(Item *vec_ord, int nr_hash, int M)
{
	int i, j;
	int *cnt = (int*)malloc(sizeof(int)*M);
	Item *b = (Item*)malloc(sizeof(Item)*nr_hash);
	
	printf("1\n");

	for (i = 0; i < nr_hash; i++) 
		cnt[vec_ord[i]->count-1]++;
	
	printf("2\n");

	for (j = 1; j < M; j++) 
		cnt[j] += cnt[j-1];
	
	printf("3\n");

	for (i = 0; i < nr_hash; i++) 
		b[cnt[vec_ord[i]->count]++] = vec_ord[i];
	
	printf("4\n");

	for (i = 0; i < nr_hash; i++)
	{
		vec_ord[i] = b[i];
		//printf("count:%d tag:%s\n", a[i].count, a[i].tag);
	}
	
	printf("5\n");

	free(b);
	free(cnt);
} */

void insert_vec_ord(Item item)
{
	if (Total_Hashtags >= len_vec)
	{
		vec_ord = (Item*) realloc(vec_ord, (len_vec+100)); 
		len_vec += 100;
	}

	vec_ord[Total_Hashtags-1] = item;
}
