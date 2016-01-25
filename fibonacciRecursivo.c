#include <stdio.h>

int fibR(int n);

int main()
{
    int n, nFib;
    
    printf("Enter the value: ");
    scanf("%d", &n);

    nFib = fibR(n);    
    
    printf("= %d \n", nFib);    
    
    return 0;
}

int fibR(int n){
    if(n<=1){
        return 1;
    }
    
    return fibR(n-1) + fibR(n-2);
}
