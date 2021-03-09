#include"operation.h"

int main(int argc , char **argv)
{
     if(argc != 2)
     {
	  printf("\n Usage : ./operation <expression>");
	  return 84;
     }

     printf("\n %s = %d\n", argv[1], calc(argv[1]));

     return 0;
}

