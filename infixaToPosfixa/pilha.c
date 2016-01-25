#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"

pilha_p PILHA_novo(){
   pilha_p p;
   p = (pilha_p) malloc(sizeof(pilha_t));
   //verifica erro no malloc
   p->lista = LISTA_novo();
   return p;
}

void PILHA_empilha(pilha_p p, item it){
   LISTA_insereNoComeco(p->lista, it);
}

item PILHA_desempilha(pilha_p p){
   if(PILHA_vazia(p)){
      printf("Erro \n");
      exit(1);
   }
   item it = LISTA_primeiroElemento(p->lista);
   LISTA_remove(p->lista);
   return it;
}

int PILHA_vazia(pilha_p p){
   return LISTA_vazia(p->lista);
}

void PILHA_destroi(pilha_p p){
   item it;
   while(!PILHA_vazia(p)){
      it = PILHA_desempilha(p);
      //free(it);
   }
   free(p->lista);
   free(p);   
}

void PILHA_imprime(pilha_p p){
   int count;
   celula_p cel;
   cel=p->lista->prox;

   while(cel != NULL){
      printf("%c\n", cel->info);
      cel = cel->prox;
   }

   printf("\n");
}
