#include <stdio.h>
#include <stdlib.h>

void zeraMatriz(char **m);

int main () {
    int i, j;
    char **m = (char**) malloc( 4 * sizeof (char*));
 
    for (i = 0; i < 4; i++)
        *(m+i) = malloc ( 5 * sizeof (char));
        
    zeraMatriz (m);

    m[1][3] = '9';
    *(*(m+2) + 3) = '5';

    for (i = 0; i < 4; i++) {
        for(j = 0; j < 5; j++)
            printf("%c ", m[i][j]);

        printf("\n");
    }

    return 0;
}

void zeraMatriz (char **m) {
    int i, j;

	for (i = 0; i < 4; i++) {
        for (j= 0; j < 5; j++)
            m[i][j] = '0';
    }
}
