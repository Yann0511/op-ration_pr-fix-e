#ifndef OPERATION
#define OPERATION

#include"pile.h"
#include<string.h>

struct calc
{
     int p_1;
     int p_2;
     char operant;
};

int conversion(char c);

int calc_unit(struct calc *O);

int calc(char* buf);

#endif
