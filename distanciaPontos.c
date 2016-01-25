//COMPILAR COM -lm

#include <stdio.h>
#include <math.h>

float distancia(int x1, int x2, int y1, int y2);

int main()
{
    int x1, x2, y1, y2, valorDistancia;
    
    printf("Input x1, x2, y1, y2: ");
    scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
    
    valorDistancia = (int) distancia(x1, x2, y1, y2);
    
    printf("A distancia entre os pontos e: %d \n", valorDistancia);

    return 0;
}

float distancia(int x1, int x2, int y1, int y2){
    int dx, dy;
    
    dx = x1 - x2;
    dy = y1 - y2;
    
    return sqrtf(dx*dx + dy*dy);
}
