#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMSEP 11
#define MAX 140

int Total_Hashtags;
int Total_Ocorrencias; // Counting Sort na Arvore    ->    M = Total_Ocorrencias
Item Maior;




static const char separators[] = {' ', '\t',',',';','.','?','!','"','\n',':','\0'};

 void split(char *line)
 {
  char *token = strtok(line, separators);
   while(token != NULL) 
  {
    if(token[0] == '#')
    {
      int i;

      Total_Ocorrencias++;

      for(i = 1; token[i]; i++)
      {
        token[i] = tolower(token[i]);
      }

      insere(token); // Tem de confirmar se foi inserido ou se ja exestia, no caso de ser inserido incrementa o Total_Hashtags
      compara_maior(token); // Compara com o Hashtag mais popular e confirma se passa a ser este o mais popular

      }
    token = strtok(NULL, separators);
  }
}



 int main()
 {
  char input = 'U'; /* Inicialiazada a 'U' para entrar no ciclo
             apenas 1 vez. Não corresponde a nenhuma
             funcao. */

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
          
          printf("%s %d\n",  Maior->tag, Maior->count);
          break;
        
        case 'l':   
          //Imprime todas as Hashtags e respetivos n de ocorrencias por ordem decrescente (em caso de empate, por ordem alfabetica)
          int i;	
          for (i = 0; i < Total_Hashtags; ++i)
          {
          	printf("%s %d\n", nome_hash(i), numero_ocor(i));
          }
          break;
                    
          
        default:
        
          printf("Comando nao reconhecido, por favor reintroduza a operacao.\n");
        
      }
    
    }
 
    return 0;
    
  }

