#include <stdio.h>
#include "vetores.h"

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

