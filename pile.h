#ifndef  PILE
#define PILE

#include <stdio.h>
#include <stdlib.h>

#if defined(TABLEAU)
struct pile
{
     void *tab;
     int taille;
};

#else
struct element
{
     void *value;
     struct element *next;
};

struct pile
{
     struct element *head;
};
#endif

struct pile *create();

void *depile(struct pile*);

void empile(struct pile*, void*);

void print(struct pile*, int);

#endif
