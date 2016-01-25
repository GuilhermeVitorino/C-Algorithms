#include <stdio.h>

int fatR(int n);

int main()
{
    int n, nFat;
    
    printf("Enter the value: ");
    scanf("%d", &n);

    nFat = fatR(n);    
    
    printf("%d fatorial e igual a: %d \n", n, nFat);    
    
    return 0;
}

int fatR(int n){
    if(n==0){
        return 1;
    }
    
    return n * fatR(n-1);
}
