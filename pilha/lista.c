#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

celula_p LISTA_novo(){
   celula_p cabeca;
   cabeca = (celula_p) malloc(sizeof(*cabeca));

   if(cabeca == NULL){
      printf("Erro no malloc da cabeca \n");
      exit(1);
   }
   
   return cabeca;
}

void LISTA_insereNoComeco(celula_p cabeca, item it){
   celula_p novo = malloc(sizeof(celula_t));
   
   novo->info = it;
   novo->prox = cabeca->prox;
   
   cabeca->prox = novo;
}

void LISTA_remove(celula_p cabeca){
   if(LISTA_vazia == 0) return;
   celula_p aux = malloc(sizeof(celula_t));
   
   aux = cabeca->prox;
   cabeca->prox = aux->prox;

   free(aux);
}

int LISTA_tamanho(celula_p cabeca){
   int count;
   celula_p cel;
   cel=cabeca->prox;

   while(cel != NULL){
      count++;
      cel=cel->prox;
   }

   return count;
}

int LISTA_vazia(celula_p cabeca){
   return cabeca->prox == NULL;
}

void LISTA_insereNaOrdem(celula_p cabeca, item it){
   celula_p novo, anterior, atual;

   novo = malloc(sizeof(*novo));
   anterior = malloc(sizeof(*anterior));
   atual = malloc(sizeof(*atual));
   
   //checar mallocs
   
   anterior = cabeca;
   atual = cabeca->prox;
   novo->info = it;

   while(atual != NULL){
      if(atual->info > it)
         break;
     
      anterior = anterior->prox;
      atual = atual->prox;
   }

   novo->prox = anterior->prox;
   anterior->prox = novo;
}

void imprimeLista(celula_p cabeca){
   int count;
   celula_p cel;
   cel=cabeca->prox;

   while(cel != NULL){
      printf("%c ", cel->info);
      cel = cel->prox;
   }

   printf("\n");
}

item LISTA_primeiroElemento(celula_p cabeca) {
   return (item) cabeca->prox->info;
}
