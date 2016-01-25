#include <stdio.h>
#include <stdlib.h>


int busca(int *v, int n, int val);
int insereNoComeco(int *v, int n, int val);
int removeE(int *v, int n, int val);
int imprimeVetor(int *v, int n);

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

int busca(int *v, int n, int val){
	if(n == 0)
		return -1;
    
    if(v[n-1] == val)
        return n-1;

    return busca(v, n-1, val);
}

int insereNoComeco(int *v, int n, int val){
   int i;

   for(i=n-1; i>0; i--)
      v[i] = v[i-1];
   
   v[0] = val;

   return n+1;
}

int removeE(int *v, int n, int val){
   int i;
   
   for(i=0; i<n; i++)
      if(v[i] == val)
         break;

  for(i=i; i<n-1; i++)
      v[i] = v[i+1];

   return i;     
}

int imprimeVetor(int *v, int n){
    int i;
   
	for(i=0; i<n; i++)
      printf("%d ", v[i]);
    printf("\n");
}

