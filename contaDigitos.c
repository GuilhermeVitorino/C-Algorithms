#include <stdio.h>

int main()
{
    int n, d, qtd=0;
    
    printf("Input the number: ");
    scanf("%d", &n);
    
    printf("Input the digit: ");
    scanf("%d", &d);

    qtd = contaDigitos(n, d);
    
    printf("O numero %d possui %d numeros iguais a %d \n", n, qtd, d);
    return 0;
}

int contaDigitos(int n, int d){
    
    int count, m;
    
    m = n;
    
    while(m != 0){
        if(m%10 == d){
            count++;
        }
        m = m/10;
    }
    
    return count;
}