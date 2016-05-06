#ifndef _ArvoreBinaria_
#define _ArvoreBinaria_ 
#ifndef _stdlib_
#define _stdlib_ 

#include "Item.c"

link NovaArvore(Item item, link l, link r){
    
    link x = (link) malloc(sizeof(struct node)); 
	x -> item = item;
	x -> l = l;  
	x -> r = r;
	return x;
	 
}

link procura(link h, Item v){
	
  if (h == NULL)
    return NULL; 
  
  if (eq(v, h->item))
    return h;
    
  if (less(v, h->item)) 
    return procura(h->l, v); 
  else
    return procura(h->r, v);
    
}


link insere(link h, Item item){ 
   
   if (h == NULL)  
      return NovaArvore(item, NULL, NULL); 
   
   if (less(item, h->item)) 
      h->l = insere(h->l, item); 
   else 
      h->r = insere(h->r, item); 
   
   return h; 

}


int altura(link h){ 

	int u, v;  
    
    if (h == NULL)
        return 0; 
	u = height(h->l);  
	v = height(h->r);  
    
    if (u > v)
        return u+1;  
    else       
        return v+1; 

}

#endif
#endif

