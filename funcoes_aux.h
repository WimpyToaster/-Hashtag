#ifndef _FUNCOES_AUX_
#define _FUNCOES_AUX_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ArvoreBinaria.h"
#include "Item.h"

extern int Total_Hashtags;
extern link global_h;
extern Item Maior;

void avalia_hash(char *token);
void counting_sort(int *a, int vec_len, int M);

#endif
