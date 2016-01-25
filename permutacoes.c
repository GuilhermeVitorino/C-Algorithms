#include <stdio.h>

int main()
{
   int n1, n2, digitosN1, digitosN2, nTemp, boolean i, j;
 
   printf("Input first number!\n");
   scanf("%d", &n1);
    
   printf("Input second number\n");
   scanf("%d", &n2);
    
   digitosN1 = contaDigitos(n1);
   digitosN2 = contaDigitos(n2);
    
    if(digitosN1 != digitosN2)
    {
        printf("Os numeros nao sao permutacoes!");
        return 0;
    }
    
    int vetN1[digitosN1], vetN2[digitosN2];
    
    for(i = 0; i < digitosN1; i++) 
    {
        vetN1[i] = n1%10;
        n1 = n1/10;
    }
    
    for(i = 0; i < digitosN2; i++) 
    {
        vetN2[i] = n2%10;
        n2 = n2/10;
    }
    
    for(i = 0; i < digitosN1; j++) 
    {
        nTemp = vetN1[i];
        boolean = 0;
        
        for(j = 0; j < digitosN2; j++) 
        {
           if(nTemp == vetN2[j])
           {
              boolean = 1;
              j = digitosN2;
           }
        }
        
        if(boolean == 0) {
            printf("Os numeros nao sao permutacoes!");
            i = digitosN1;
        }
    }
    
    if(boolean == 1) {
            printf("Os numeros sao permutacoes!");
            i = digitosN1;
    }
    
    return 0;
}

int contaDigitos(int num)
{
   int digitos = 0;
   
    do
      {
         digitos += 1;
         num = num / 10;
      }
    while (num != 0);
   
   return digitos; 
}
