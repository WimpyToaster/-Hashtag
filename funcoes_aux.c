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

