#include <stdio.h>

int main()
{
    int n, nFat = 1, i;
    
    printf("Enter the value: ");
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++) {
       nFat = nFat * i;    
    }
    
    printf("%d fatorial e igual a: %d \n", n, nFat);    
    
    return 0;
}