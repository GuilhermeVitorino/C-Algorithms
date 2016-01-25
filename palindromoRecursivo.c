#include <stdio.h>
#include <stdlib.h>

int palindromoR(char *s	, int t);

int main()
{
    int n, nAux, count=0, i=0, boolean;
    char *s;
    
    printf("Enter the value: ");
    scanf("%d", &n);

    nAux = n;

    //verifica a quantidade de algarismos que n possui
    while(nAux != 0){
        count++;
        nAux = nAux / 10;
    }

    s = (char*) malloc(count * sizeof(char));

    nAux = n;    

    //popula o vetor de chars
    for(i=count; i>0; i--){
        s[i-1] = nAux%10; 
        nAux = nAux/10;
    }    

    boolean = palindromoR(s, count);    
    
    if(boolean == 1){
        printf("E um palindromo! \n");
    }else{
        printf("Nao é um palindromo \n");
    }

    return 0;
}

int palindromoR(char *s, int t){
    if(t == 1){
        return 1;
    }
    
    if(s[0] != *(s+(t-1))){
        return 0;
    }
    
    return palindromoR(s+1, t-2);
}
