#include <stdio.h>

void pontoMedio(int x1, int y1, int x2, int y2, int *memX, int *memY);

int main()
{
    int x1, y1, x2, y2, xm, ym, *memX, *memY;
    
    printf("Input x1, y1, x2, y2: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	memX =(int*) malloc(sizeof(int));
    memY =(int*) malloc(sizeof(int));
        
    pontoMedio(x1, y1, x2, y2, memX, memY);
    
    xm = *memX;
    ym = *memY;

    printf("xm = %d \n", xm);
    printf("ym = %d \n", ym);
    
    printf("endereco memX = %d \n", memX);
    printf("endereco memY = %d \n", memY);

    return 0;
}

void pontoMedio(int x1, int y1, int x2, int y2, int *memX, int *memY){	
    int xm, ym;
    xm = (x1 + x2)/2;
    ym = (y1 + y2)/2;
    
    *memX = xm;
    *memY = ym;    
}
