#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
   celula_p lista = LISTA_novo();
   
   LISTA_insereNoComeco(lista, 'z');  
   LISTA_insereNoComeco(lista, 'h');
   LISTA_insereNoComeco(lista, 'd');
   LISTA_insereNoComeco(lista, 'g');
   LISTA_insereNoComeco(lista, 'i');
   LISTA_insereNoComeco(lista, 'p');
 
   imprimeLista(lista);

   printf("Removendo o primeiro elemento da lista... \n");
   LISTA_remove(lista);
   imprimeLista(lista);

   printf("Tamanho da lista = %d \n", LISTA_tamanho(lista));
   
   printf("Lista vazia = %d \n", LISTA_vazia(lista));

   printf("Insere na ordem o elemento 'k'... \n");
   LISTA_insereNaOrdem(lista, 'k');
   imprimeLista(lista);
   
   return 0;
}
