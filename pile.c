#include "pile.h"

struct pile *create()
{
     struct pile *Pile = malloc(sizeof(struct pile));

     if(!Pile)
     {
	  printf("\n Allocation echoué");
	  return NULL;
     }

#if defined(TABLEAU)
     Pile->tab = calloc(0, sizeof(void*));
     Pile->taille = -1;

#else
     Pile->head = NULL;

#endif
     return Pile;
}

void empile(struct pile *pile,void *value)
{
     struct element* new = NULL;

     if(pile)
     {
#if defined(TABLEAU)
	  pile->taille++;
	  pile->tab = realloc(pile->tab,pile->taille + 1);
	  *(pile->tab + pile->taille) = *value;
#else
	  new = calloc(0, sizeof(struct element));
	  new->value = value;
	  new->next = pile->head;
	  pile->head = new;
#endif
     }
}


void *depile(struct pile *pile)
{
     void *res = NULL;

#if defined(TABLEAU)
     if(pile->taille == -1)
	  return NULL;

     res = pile->tab + pile->taille;
     pile->taille --;
     
#else
     struct element *tmp;

     if (pile->head)
     {
	  res = pile->head->value;
	  tmp = pile->head;
	  pile->head = pile->head->next;
	  free(tmp);
     }
#endif
     return res;
}
