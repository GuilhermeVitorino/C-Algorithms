//algoritmo caminho minimo de Dijkstra
#include <stdio.h>
#include <stdlib.h>

int *distancias (int **A, int n, int o);

int main() {

   int **A, *d, i;
   
   A = (int **) malloc (6 * sizeof (int));
   d = malloc (6 * sizeof (int));
  
   for (i = 0; i < 6; i++)
      A[i] = (int *) malloc (6 * sizeof (int)); 
  

   A[0][1] = 1;
   A[1][2] = 1;
   A[2][4] = 1;
   A[3][2] = 1;
   A[3][4] = 1;
   A[4][0] = 1;
   A[5][1] = 1;
   A[1][5] = 1;
   
   d = distancias(A, 6, 3);

   for (i = 0; i < 6; i++)
      printf("%d ", d[i]);

   printf("\n");
   
   free(d);

   for (i = 0; i < 6; i++)
      free(A[i]);


}

int *distancias (int **A, int n, int o) {
   int *d, x, y;
   int *f, s, t;

   d = malloc (n * sizeof (int));
  
   for (x = 0; x < n; x++)
      d[x] = -1;

   d[o] = 0;

   f = malloc (n * sizeof (int));
   
   s = 0; t = 1; f[s] = o;

   while (s < t) {
      x = f[s++];	
      for (y = 0; y < n; y++)
         if (A[x][y] == 1 && d[y] == -1) {
            d[y] = d[x] + 1;
            f[t++] = y;    
         }
   }

   free(f);
   return d;
} 
