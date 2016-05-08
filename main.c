#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ArvoreBinaria.h"
#include "funcoes_aux.h"
#include "Item.h"

#define NUMSEP 11
#define MAX 140


int Total_Hashtags;
int Total_Ocorrencias; // Counting Sort na Arvore    ->    M = Total_Ocorrencias
Item Maior;
link global_h = NULL;
static const char separators[] = {' ', '\t',',',';','.','?','!','"','\n',':','\0'};

 
void split(char *line);

int main()
{
  char input = 'U'; /* Inicialiazada a 'U' para entrar no ciclo
             apenas 1 vez. Não corresponde a nenhuma
             funcao. */
  //int i; 
  Total_Hashtags = 0;
  Total_Ocorrencias = 0;
             
  char mensagem[MAX + 1];
      
    while ((input=getchar()) != 'x')
    {
                    
      switch (input)
      {
        case 'a':
          // Recebe a linha introduzida e divide-a em palavras separadas, selecionando os Hashtags
          fgets(mensagem, MAX + 1, stdin);
          split(mensagem);        
          break;
        
        case 's':
          
          printf("%d %d\n", Total_Hashtags, Total_Ocorrencias);        
          break;
        
        case 'm':  
          
          printf("%s %d\n",  Maior.tag, Maior.count);
          break;
        
        case 'l':   
          //Imprime todas as Hashtags e respetivos n de ocorrencias por ordem decrescente (em caso de empate, por ordem alfabetica)
          /*for (i = 0; i < Total_Hashtags; ++i)
          {
            //printf("%s %d\n", v[i], v[i]);
          } */
          traverse(global_h);
          break;
                    
          
      
        
      }
    
    }
 
    return 0;
    
 }


void split(char *line)
{
  
  char *token = strtok(line, separators);
   while(token != NULL) 
  {
    if(token[0] == '#')
    {
      Total_Ocorrencias++;
      
      int i;

      for(i = 1; token[i] != '\0'; i++)
      {
        token[i] = tolower(token[i]);
      } 

      avalia_hash(token); // Confirmar se a hashtag foi inserido ou se ja exestia, no caso de ser inserido incrementa o Total_Hashtags
    }
    token = strtok(NULL, separators);
  }
}
