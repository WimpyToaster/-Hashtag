#include "funcoes_aux.h"
#include "Item.h"
#include "ArvoreBinaria.h"

#define INIT 100

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
			if (Maior->count == existe->item->count)
			{
				if (strcmp(Maior->tag, existe->item->tag) > 0)
					Maior = existe->item;
			}
			

			free(hash->tag);
			free(hash);
		}
	}
}



void insert_vec_ord(Item item)
{
	if (Total_Hashtags == len_vec)
	{
		
		vec_ord = (Item*) realloc(vec_ord, sizeof(Item)*(len_vec+INIT)); 
		len_vec += INIT;
		
	}

	vec_ord[Total_Hashtags-1] = item;
}

void sort()
{
	qsort(vec_ord, Total_Hashtags, sizeof(Item), cmp_item);
}

int cmp_item(const void *i, const void *j)
{
	Item my_i = *(Item*)i;
	Item my_j = *(Item*)j;

	if(my_i->count == my_j->count)
		return strcmp(my_i->tag, my_j->tag);

	return my_j->count - my_i->count;
}

/*
void tree_to_vec(link h)
{

	if (h == NULL)
		return;
 
	free_tree(h->l);
	insert_vec_ord(h->item);
	free_tree(h->r);
	
}*/

/* 
para chamar: 
bucket_sort(vec_ord, Total_Hashtags, Maior->count);
* isto so convem ser testado depois de o programa estar
* completamente funcional, tem de se remover todas as
* insercoes de Item's no vec_ord e fazer uma funcao que
* faca isso a partir da arvore 
* (esta é prototipo nao consegui testar por causa 
*      de memory leaks) 	
void tree_to_vec(link h)
{
	if (h == NULL)
		return;
 
	free_tree(h->l);
	insert_vec_ord(h->item);
	free_tree(h->r);
	
}
* alem disso nao ha muitas garantias que este bucket funcione
* apesar de ja ter testado um bom bocado.
void bucket_sort(Item *a, int nr_hash, int M)
{
	int i;
	int *cnt = (int*)malloc(sizeof(int)*(M+1));
	Item *b = (Item*)malloc(sizeof(Item)*nr_hash);
	
	for (i = 0; i < nr_hash; i++) 
		cnt[a[i]->count + 1]++;
		
	for (i = 1; i <= M; i++) //aki tem a soma acumlutativa 
		cnt[i] += cnt[i-1];
		
	for (i = 0; i < nr_hash; i++) 
		b[cnt[a[i]->count]++] = a[i]; 
	
	for (i = 0; i < nr_hash; i++)
	{
		a[i] = b[(nr_hash - 1) - i]; 
		 
	}
	
	free(b);
	free(cnt);
}
*/
