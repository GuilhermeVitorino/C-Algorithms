#ifndef LISTA_H_
#define LISTA_H_

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
item LISTA_primeiroElemento(celula_p cabeca);

#endif
