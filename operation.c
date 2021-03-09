#include"operation.h"

int conversion(char c)
{
     if(c == '0')
	  return 0;

     if(c == '1')
	  return 1;

     if(c == '2')
	  return 2;

     if(c == '3')
	  return 3;

     if(c == '4')
	  return 4;

     if(c == '5')
	  return 5;

     if(c == '6')
	  return 6;

     if(c == '7')
	  return 7;

     if(c == '8')
	  return 8;

     if(c == '9')
	  return 9;
}
	  
int calc_unit(struct calc* O)
{
     if(O->operant == '+')
	  return O->p_1 + O->p_2 ;

     else if(O->operant == '-')
	  return O->p_1 - O->p_2 ;

     else if(O->operant == '*')
	  return O->p_1 * O->p_2 ;

     else if(O->operant == '/')
	  return O->p_1 / O->p_2 ;

     else
	  printf("\n Operatant non reconnu\n") ;
}

int calc(char* buf)
{
     struct pile* operations = create(), *valeurs = create();
     struct calc* calcul = malloc(sizeof(struct calc));
     int i;
     
     for (i = 0; i < strlen(buf); i++)
     {
	  if(strchr("+*/-",buf[i]))
	  {
	       if(strchr("+*/-",buf[i+1]) || strchr("+*/-",buf[i+2]))
		    empile(operations,(void *)buf[i]);

	       else
	       {
		    calcul->p_1 = conversion(buf[i+1]);
		    calcul->p_2 = conversion(buf[i+2]);
		    calcul->operant = buf[i];
		    empile(valeurs,(void *)calc_unit(calcul));
		    i+= 2;
	       }
	  }
	  
        else
	     empile(valeurs,(void *)conversion(buf[i]));
     }

     for(calcul->operant = (char)depile(operations); calcul->operant; calcul->operant = (char)depile(operations))
     {
	  calcul->p_1 = (int)depile(valeurs);
	  calcul->p_2 = (int)depile(valeurs);
	  empile(valeurs,(void *)calc_unit(calcul));
     }

     return (int)depile(valeurs);
}
