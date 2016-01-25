#include <stdio.h>

struct _ponto{
    int x;
    int y;
};

typedef struct _ponto ponto;

ponto pontoMedio(ponto p1, ponto p2);

int main()
{
    struct _ponto p1, p2;
    ponto pm;
    
    printf("Input x1, x2, y1, y2: ");
    scanf("%d %d %d %d", &(p1.x), &(p2.x), &(p1.y), &(p2.y));
    
    printf("p1.x = %d \n", p1.x);
    printf("p2.x = %d \n", p2.x);
    printf("p1.y = %d \n", p1.y);
    printf("p2.y = %d \n", p2.y);
    
    pm = pontoMedio(p1, p2);
    
    printf("xm = %d \n", pm.x);
    printf("ym = %d \n", pm.y);
    
    printf("end xm = %d \n", &pm.x);
    printf("end ym = %d \n", &pm.y);

    return 0;
}

ponto pontoMedio(ponto p1, ponto p2){
    ponto pm;
    pm.x = (p1.x + p2.x)/2;
    pm.y = (p1.y + p2.y)/2;
    return pm;
}