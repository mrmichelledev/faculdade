#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main() {
    Pilha* pi = cria_pilha();
    char exp[50] = "5 3 2 4 6 7 1 + * + * + *"; 
    //5 * (3 + (2 * (4 + (6 * 8))))) = 535

    printf("Resultado de %s:\t", exp);
    printf("%.2f\n", resolver_expressao(pi, exp));

    libera_pilha(pi);
    return 0;
}
