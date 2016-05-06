#include "funcoes_aux.h"
#include "Item.h"
#include "ArvoreBinaria.h"
#include <stdlib.h>
#include <stdio.h>

void avalia_hash(char *token)
{

	if (Total_Hashtags == 0)
	{	
		Item primeira_hash;
		primeira_hash.tag = token;
		primeira_hash.count = 1;
		
	    global_h = NewTree(primeira_hash, NULL, NULL);
	    Total_Hashtags++;
	    Maior = global_h->item;	    
	}

	else
	{
		
		Item hash;
		hash.tag = token;
		link existe = search(global_h, hash);
		
		if(existe == NULL) 
		{
			hash.count = 1;

			global_h = insert(global_h, hash);
			Total_Hashtags++;
			
			if(Maior.count == 1)
			{
				if(strcmp(Maior.tag, hash.tag) > 0)
					Maior = hash;
			}
			
		}
		
		else
		{
			existe->item.count++;
			
			if(existe->item.count > Maior.count)
				Maior = existe->item;

		}
	}
}


void counting_sort(int *a, int vec_len, int M)
{    
	/* keys go from 0 to M, neste caso é o numero de ocurrencias maximo! */

	int i, j, cnt[M];
	int *b = (int*)malloc(sizeof(int)*vec_len);
	
	for (j = 0; j < M; j++) /* inicializao do vetor auxiliar a 0 */
		cnt[j] = 0;
		
	for (i = 0; i < vec_len; i++) /* construcao do histograma */
		cnt[a[i]+1]++;
	
	for (j = 1; j < M; j++) /* soma acumulativa do histograma */
		cnt[j] += cnt[j-1];
	
	for (i = 0; i < vec_len; i++) /* construcao do vetor auxiliar */
		b[cnt[a[i]]++] = a[i];
	
	for (i = 0; i < vec_len; i++)
		a[i] = b[i]; 

	free(b);

}
