#ifndef PILHA_H_
#define PILHA_H_
#include "lista.h"

typedef struct pilha pilha_t;
typedef struct pilha* pilha_p;

struct pilha {
   celula_p lista;   
};

pilha_p PILHA_novo();
void PILHA_empilha(pilha_p p, item it);
item PILHA_desempilha(pilha_p p);
int PILHA_vazia(pilha_p p);
void PILHA_destroi(pilha_p p);
void PILHA_imprime(pilha_p p);

#endif
