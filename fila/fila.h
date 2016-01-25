#ifndef FILA_H_
#define FILA_H_

typedef char item;

struct fila {
   item *v;
   int ini, fim, tamMax;   
};

typedef struct fila fila_t;
typedef struct fila *fila_p;


fila_p FILA_novo (int tamMax);
void FILA_enfileira (fila_p f, item it);
item FILA_desenfileira (fila_p f);
int FILA_cheia (fila_p f);
int FILA_vazia (fila_p f);
int FILA_tamanho (fila_p f);
void FILA_destroi (fila_p f);

#endif
