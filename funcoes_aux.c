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
	free_tree(h->r);
	insert_vec_ord(h->item);
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
		 
		// isto eh debug!!!! 
		printf("tag:%s\ncount:%d\n\n",a[i]->tag,a[i]->count);
	}
	
	free(b);
	free(cnt);

}
*/
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
