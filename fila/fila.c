#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

fila_p FILA_novo(int tamMax) {
   fila_p f;

   f = malloc(sizeof (*f));
   f->v = malloc(tamMax + 1 * sizeof (item));
   //verifica mallocs

   f->ini = f->fim = 0;
   f->tamMax = tamMax + 1;
   return f;
}

void FILA_enfileira (fila_p f, item it) {
   if(FILA_cheia(f) == 1){
      printf("Fila cheia! \n");
      exit(1);
   }
   
   f->v[f->fim] = it;
   f->fim = (f->fim + 1) % f->tamMax;
}

item FILA_desenfileira (fila_p f) {
   item it;

   if(FILA_vazia(f) == 1){
      printf("Fila vazia! \n");
      exit(1);
   }
   
   it = f->v[f->ini];
   f->ini = (f->ini + 1) % f->tamMax;
   return it;
}

int FILA_cheia (fila_p f) {
   return (f->fim + 1) % f->tamMax == f->ini;
}

int FILA_vazia (fila_p f) {
   return f->ini == f->fim;
}

int FILA_tamanho (fila_p f) {
   return (int) (f->fim - f->ini + f->tamMax) % f->tamMax;
}

void FILA_destroi (fila_p f) {
   item it;

   while (!FILA_vazia(f)) {
      it = FILA_desenfileira(f);
      //item_destroi(it)
   }
   free(f->v);
   free(f);
}
