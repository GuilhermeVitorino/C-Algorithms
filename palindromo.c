#include <stdio.h>

int main()
{
    int n, revert = 0, aux;
    
    printf("Enter the value: ");
    scanf("%d", &n);
    
    aux = n;
    
    while(aux != 0) {
       revert = revert * 10;
       revert += aux % 10;
       aux = aux / 10;     
    }
    
    if (n == revert)
    {
       printf("E um palindromo\n");    
    } 
    else
    {
       printf("Nao e um palindromo\n");    
    }
    
    return 0;
}