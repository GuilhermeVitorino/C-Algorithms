#include <stdio.h>
#include <stdlib.h>

typedef char item;

struct celula {
   item info;
   struct celula *prox;
};

typedef struct celula celula_t;
typedef struct celula* celula_p;


celula_p LISTA_novo();
void LISTA_insereNoComeco(celula_p cabeca, item it);
void LISTA_remove(celula_p cabeca);
int LISTA_tamanho(celula_p cabeca);
int LISTA_vazia(celula_p cabeca);
void LISTA_insereNaOrdem(celula_p cabeca, item it);
void imprimeLista(celula_p cabeca);

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
   
}

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
   int tamanho;

   tamanho = LISTA_tamanho(cabeca);

   if(tamanho != 0)
      return 1;

   return tamanho;
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
