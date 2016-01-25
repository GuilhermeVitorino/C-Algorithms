#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h" 

/* A funcao recebe uma expressao infixa
 * e devolve uma expressao posfixa. */
char *traduzPosFixa (char *infixa, int n);

/* A funcao recebe uma expressao poxfixa
 * e devolve o resultado da expressao. */
int calculaPosFixa (char *posfixa, int n);

char main (int argc, char **argv) {
	char *posfixa;
	int length;

    *argv++;
    argc--;

    
    printf("EXPRESSAO INFIXA: %s \n\n", *argv);
    
    length = strlen(*argv);
    posfixa = traduzPosFixa (*argv, length);
    printf("EXPRESSAO POSFIXA: %s \n\n", posfixa);
    
    length = strlen(posfixa);
    printf("RESULTADO DA EXPRESSAO POSFIXA: %d \n\n", calculaPosFixa(posfixa, length+1));
}

char *traduzPosFixa (char *infixa, int n) {
	char *posfixa, c, c_aux;
	int i, j = 0;
	pilha_p p;

	posfixa = malloc((n+1) * sizeof (char));
	p = PILHA_novo();

	for (i = 0; i < n; i++) {

		c = infixa[i];

		if (c == '(') {
			PILHA_empilha(p, c);
		}

		else if (c == ')') {
            c_aux = PILHA_desempilha(p);
                        
            while (c_aux != '(') {
               posfixa[j++] = c_aux;
               c_aux = PILHA_desempilha(p);              	
            }
		}

		else if (c >= '0' && c <= '9'){
			posfixa[j++] = c;
		}

		else if ('*' == c || c == '/'){
			while (!PILHA_vazia(p)) {
				c_aux = PILHA_desempilha(p);

				if (c_aux == '(' || c_aux == '+' 
					|| c_aux == '-') {
					
					PILHA_empilha(p, c_aux);
					break;
				}
				posfixa[j++] = c_aux;
			}
			PILHA_empilha(p, c);
		}

		else if ('+' == c || c == '-'){
			while (!PILHA_vazia(p)) {
				c_aux = PILHA_desempilha(p);

				if (c_aux == '(') {

					PILHA_empilha(p, c_aux);
					break;
				}

				posfixa[j++] = c_aux;
			}
			PILHA_empilha(p, c);
		}
	}

	while (!PILHA_vazia(p)) {
		c = PILHA_desempilha(p);
        posfixa[j++] = c;
	}

	free(p);
	posfixa[j] = '\0';

    return posfixa;
}

int calculaPosFixa (char *posfixa, int n) {
	int i, a, b, x, res;
	pilha_p p;
	char c;

	p = PILHA_novo();

	for (i = 0; i < n-1; i++) {
		c = posfixa[i];

		if (c >= '0' && c <= '9') {
			
			x = c - '0';
			PILHA_empilha(p, x);

	    } else {
			
			b = PILHA_desempilha(p);
			a = PILHA_desempilha(p);

			if (c == '+') {
				x = a + b;
			}

			else if (c == '-') {
				x = a - b;
			}

			else if (c == '/') {
				x = a / b;
			}

			else if (c == '*') {
				x = a * b;
			}
            
			PILHA_empilha(p, x);

		}		
	}

	res = PILHA_desempilha(p);

	free(p);
	return res;
}