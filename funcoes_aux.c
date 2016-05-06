extern int Total_Hashtags;

void poe_hash(char *token)
{

	if (Total_Hashtags == 0)
	{
	
		Item primeira_hash;
		primeira_hash.tag = token;
		primeira_hash.count = 1;
		
	    global_h = NovaArvore(primeira_hash, NULL, NULL);
	    
	}
	else
	{
		
		Item hash;
		hash.tag = token;
		link *existe = procura(global_h, hash);
		
		if(existe == NULL) 
		{
			global_h = insere(global_h, hash);
			Total_Hashtags++;
		}
		
		else
		{
			existe -> count++;
		}
	}
}


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

       poe_hash(token); // Tem de confirmar se foi inserido ou se ja exestia, no caso de ser inserido incrementa o Total_Hashtags
      //compara_maior(token); // Compara com o Hashtag mais popular e confirma se passa a ser este o mais popular

      }
    token = strtok(NULL, separators);
  }
}
