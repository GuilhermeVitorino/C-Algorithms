#include <stdio.h>

int main()
{
    int n1, n2, i;
    
    printf("Input the firt number: ");
    scanf("%d", &n1);
    
    printf("Input the second number: ");
    scanf("%d", &n2);
    
    for(i = 0; i < 10; i++){
       
        if(contaDigitos(n1, i) != contaDigitos(n2, i)){
            printf("Nao sao permutacao!");
            break;
        }
    }
    
    if(i == 10){
        printf("Sao permutacao!");    
    }
    
    return 0;
}

int contaDigitos(int n, int d){
    
    int count=0, m;
    
    m = n;
    
    while(m != 0){
        if(m%10 == d){
            count++;
        }
        m = m/10;
    }
    
    return count;
}