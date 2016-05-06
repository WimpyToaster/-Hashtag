#include "ArvoreBinaria.h"

link NewTree(Item item, link l, link r)
{
    
    link x = (link) malloc(sizeof(struct node)); 
	x -> item = item;
	x -> height = 1;
	x -> l = l;  
	x -> r = r;
	return x;
	 
}

link search(link h, Item v)
{
	
  if (h == NULL)
    return NULL; 
  
  if (eq(v, h->item))
    return h;
    
  if (less(v, h->item)) 
    return search(h->l, v); 
  else
    return search(h->r, v);
    
}


link insert(link h, Item item)
{ 
   
   if (h == NULL)  
      return NewTree(item, NULL, NULL); 
   
   if (less(item, h->item)) 
      h->l = insert(h->l, item); 
   else 
      h->r = insert(h->r, item); 
   
   h = AVLbalance(h);
   
   return h;

}


int height(link h)
{ 

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

link rotL(link h)  
{ 

	int height_left, height_right; 
    
    link x = h->r;
    h->r = x->l;
    x->l = h;
    
    height_left = height(h->l); 
    height_right = height(h->r); 
    h->height = height_left > height_right ? height_left + 1 : height_right + 1;
    
	height_left = height(h->l); 
	height_right = height(x->r); 
    x->height = height_left > height_right ? height_left + 1 : height_right + 1; 
    
    return x;
    
} 

link rotR(link h)  
{ 
	
	int height_left, height_right;
    link x = h->l;
    h->l = x->r; 
    x->r = h;
    
	height_left = height(h->l); 
	height_right = height(h->r); 
    h->height = height_left > height_right ?  height_left + 1 : height_right + 1;
     
	height_left = height(x->l); 
	height_right = height(h->r); 
    x->height = height_left > height_right ?  height_left + 1 : height_right + 1; 
    
    return x;  

} 

link rotLR(link h) /*rotação dupla esquerda direita*/ 
{ 
    if (h==NULL)
		return h; 
    
    h->l = rotL(h->l); 
    return rotR(h);  
}

link rotRL(link h) /*rotação dupla direita esquerda*/ 
{ 
    if (h==NULL)
        return h; 
    
    h->r = rotR(h->r);  
    return rotL(h);  
} 

int Balance(link h) /*Balance factor*/
{  
    
    if(h == NULL)
        return 0;  
    
    return height(h->l) - height(h->r);  
}  



link AVLbalance(link h) 
{
	int balanceFactor;
	 
    if (h==NULL)
        return h; 

	balanceFactor = Balance(h);  
    
    if(balanceFactor > 1)
    {  
        if (Balance(h->l) >= 0)
			h = rotR(h);  
        else           
            h = rotLR(h);   
    } 
    
    else if(balanceFactor < -1)
    {  
        if (Balance(h->r) <= 0)
            h = rotL(h);  
        else          
            h = rotRL(h);  
    } 
    
    else
    {	
		int height_left = height(h->l); 
		int height_right = height(h->r); 
        h->height = height_left > height_right ?  height_left + 1 : height_right + 1; 
    }
     
    return h;
    
}
