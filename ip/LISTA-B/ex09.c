#include <stdio.h>

void decomporNumero(int numero) {
    if (numero < 1 || numero > 9999) {
        printf("Numero invalido!\n");
        return;
    }
    
    int unidades = numero % 10;
    int dezenas = (numero / 10) % 10;
    int centenas = (numero / 100) % 10;
    int milhares = numero / 1000;
    
    if (milhares >=1){
       printf("(quarta ordem) %d = ", numero);
    } else if (milhares == 0 && centenas >=1){
       printf("(terceira ordem) %d = ", numero);
    } else if (milhares == 0 && centenas == 0 && dezenas >= 1){
       printf("(segunda ordem) %d = ", numero);
    } else if (milhares == 0 && centenas == 0 && dezenas == 0 && unidades >= 1){
       printf("(primeira ordem) %d = ", numero);
    }
    
    if (milhares > 0) {
        printf("%d unidade%s de milhar", milhares, (milhares > 1 ? "s" : ""));
        if (centenas > 0 || dezenas > 0 || unidades > 0) {
            printf(" + ");
        }
    }

    if (centenas > 0) {
        printf("%d centena%s", centenas, (centenas > 1 ? "s" : ""));
        if (dezenas > 0 || unidades > 0) {
            printf(" + ");
        }
    }

    if (dezenas > 0) {
        printf("%d dezena%s", dezenas, (dezenas > 1 ? "s" : ""));
        if (unidades > 0) {
            printf(" + ");
        }
    }

    if (unidades > 0) {
        printf("%d unidade%s", unidades, (unidades > 1 ? "s" : ""));
    }
    
    printf(" = ");
    
    if (numero%1000 == 0){
        if (milhares > 0) {
            printf("%d000", milhares);
            printf(" ");
        }
    } else {
        if (milhares > 0) {
            printf("%d000", milhares);
            printf(" + ");
        }
    }
    
    if (numero%100 == 0){
        if (centenas > 0) {
            printf("%d00", centenas);
            printf(" ");
        }
    } else {
        if (centenas > 0) {
            printf("%d00", centenas);
            printf(" + ");
        }
    }
    
    if (numero%10 == 0){
        if (dezenas > 0) {
            printf("%d0", dezenas);
            printf(" ");
        }
    } else {
        if (dezenas > 0) {
            printf("%d0", dezenas);
            printf(" + ");
        }
    }

    if (unidades > 0) {
        printf("%d", unidades);
        printf(" ");
    }

    printf("\n");
}

int main() {
    int numero;
    scanf("%d", &numero);
    
    decomporNumero(numero);
    
    return 0;
}