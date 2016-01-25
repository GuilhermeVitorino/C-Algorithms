#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
   pilha_p p = PILHA_novo();
   
   PILHA_empilha(p, 'a');
   PILHA_empilha(p, 'b');  
   PILHA_empilha(p, 'c');  
   PILHA_empilha(p, 'd');  
   PILHA_empilha(p, 'e');  
   PILHA_empilha(p, 'f');  
   PILHA_empilha(p, 'g');  

   PILHA_imprime(p);

   PILHA_desempilha(p);
   PILHA_desempilha(p);

   printf("Desempilhando dois elementos... \n");

   PILHA_imprime(p);
   
   return 0;
}
