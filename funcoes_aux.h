#ifndef _FUNCOES_AUX_
#define _FUNCOES_AUX_

#include <string.h>
#include "ArvoreBinaria.h"
#include "Item.h"

extern int Total_Hashtags;
extern link global_h;
extern Item Maior;
extern int len_vec;
extern Item *vec_ord;

void insert_vec_ord(Item item);
void avalia_hash(char *token, int size_str);
//void radix_sort(Item *vec_ord, int nr_hash, int M);

#endif
