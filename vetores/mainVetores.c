#include <stdio.h>
#include <stdlib.h>
#include "vetores.h"

int main()
{
    int *v, n=10;
    
    v = malloc(n*sizeof(int));
    v[0] = 8;
    v[1] = 15;
	v[2] = 16;
	v[3] = 12;
	v[4] = 3;
	v[5] = 2;
	v[6] = 7;

    imprimeVetor(v, n);

    printf("Elemento de valor 12 esta no indice %d \n", busca(v, n, 12));

    printf("\n");

    printf("Inserindo no comeco o valor 23...\n");
    insereNoComeco(v, n, 23);
    imprimeVetor(v, n);

    printf("\n");

    printf("Removendo o valor 16 do vetor...\n");
    removeE(v, n, 16);
    imprimeVetor(v, n);
}

