extern int Total_Hashtags;
extern link global_h;
extern Item Maior;

void avalia_hash(char *token)
{

	if (Total_Hashtags == 0)
	{
	
		Item primeira_hash;
		primeira_hash.tag = token;
		primeira_hash.count = 1;
		
	    global_h = NovaArvore(primeira_hash, NULL, NULL);
	    Maior = global_h->item;
	    
	}
	else
	{
		
		Item hash;
		hash.tag = token;
		link existe = procura(global_h, hash);
		
		if(existe == NULL) 
		{
			hash.count = 1;

			global_h = insere(global_h, hash);
			if(Maior.count == 1)
			{
				if(strcmp(Maior.tag, hash.tag) > 0)
					Maior = hash;
			}
			Total_Hashtags++;
		}
		
		else
		{
			existe->item.count++;

			if(existe->item.count > Maior.count)
				Maior = existe->item;

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

       avalia_hash(token); // Confirmar se a hashtag foi inserido ou se ja exestia, no caso de ser inserido incrementa o Total_Hashtags
     
     }
    token = strtok(NULL, separators);
  }
}

