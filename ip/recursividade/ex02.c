#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cont(char *texto, int tam){
    int soma;
    if(tam < 0) 
        return 0;

    if(texto[tam] == 'i' && texto[tam - 1] == 'h')
        return 1 + cont(texto, tam - 1);
    else
        return 0 + cont(texto, tam - 1);
}

int main(){
    int num, i, tam, quant;
    char texto[5000];
    scanf("%d", &num);

    for(i =0; i < num; i++){
        scanf("\n%5000[^\n]", texto);
        tam = strlen(texto);
        quant = cont(texto, tam - 1);
        printf("%d\n", quant);
    }

    return 0;
}