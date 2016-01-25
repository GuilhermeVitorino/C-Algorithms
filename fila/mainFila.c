#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define BLINE "\n\n"

int main(){
   fila_p f = FILA_novo(10);
  
   printf("Fila vazia = %d"BLINE, FILA_vazia(f));

   printf("Enfileirando 'a', 'b', 'c'... "BLINE);
   FILA_enfileira (f, 'a');
   FILA_enfileira (f, 'b');
   FILA_enfileira (f, 'c');  
   
   printf("O tamanho da fila agora e = %d"BLINE, FILA_tamanho(f));

   printf("Removendo o elemento que esta a mais tempo na fila = '%c'"BLINE, FILA_desenfileira(f));

   printf("O tamanho da fila agora e = %d"BLINE, FILA_tamanho(f));

   printf("Removendo o elemento que esta a mais tempo na fila = '%c'"BLINE, FILA_desenfileira(f));

   printf("O tamanho da fila agora e = %d"BLINE, FILA_tamanho(f));

   printf("Fila vazia = %d \n", FILA_vazia(f));

   printf("Enfileirando 'b', 'c', 'd', 'e', 'f','g', 'h', 'i', 'j'... "BLINE);
   FILA_enfileira (f, 'b');
   FILA_enfileira (f, 'c');
   FILA_enfileira (f, 'd');
   FILA_enfileira (f, 'e');
   FILA_enfileira (f, 'f');
   FILA_enfileira (f, 'g');
   FILA_enfileira (f, 'h');
   FILA_enfileira (f, 'i');
   FILA_enfileira (f, 'j');
   printf("Fila tamanho = %d \n", FILA_tamanho(f));
   printf("Fila cheia = %d \n", FILA_cheia(f));
   
   return 0;
}
