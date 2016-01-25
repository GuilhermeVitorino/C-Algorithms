#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;

int bemformada (char s[]);

int main () {

   char palavra[9];
   palavra[0] = '(';
   palavra[1] = '(';
   palavra[2] = ')';
   palavra[3] = '{';
   palavra[4] = '(';
   palavra[5] = ')';
   palavra[6] = '}';
   palavra[7] = ')';
   palavra[8] = '\0';
   
 
   printf("%d \n", bemformada (palavra));

}

/* Esta funcao devolve 1 se a string s contem
 * uma sequencia bem-formada de parenteses e chaves
 * e devolve 0 se a sequencia esta mal formada. */

/* Exemplo:
 * ( ( ) { ( ) } ) é uma sequencia bem-formada
 * ( { ) ) não é uma sequencia bem-formada. */
int bemformada (char s[]) {
   char *p; int t;
   int n, i;
 
   n = strlen (s);
   printf("%d \n", n);
   p = malloc (n * sizeof (char));
 
   t = 0;

   for (i = 0; s[i] != '\0'; i++) {
      switch (s[i]) {
         case ')': if (t != 0 && p[t-1] == '(') --t;
                   else return 0;
                   break;
         case '}': if (t != 0 && p[t-1] == '{') --t;
                   else return 0;
                   break;
         default: p[t++] = s[i];
      }
   }
   
   return t == 0;
}
