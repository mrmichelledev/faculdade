#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cont(char *vet, int tam){
    int soma;
    if(tam < 0) 
        return 0;

    if(vet[tam] == '5')
        return 1 + cont(vet, tam - 1);
    else
        return 0 + cont(vet, tam - 1);
}

int main(){
    int num, i, tam, quant;
    char vet[1000];
    scanf("%d", &num);

    for(i =0; i < num; i++){
        scanf("\n%5000[^\n]", vet);
        tam = strlen(vet);
        quant = cont(vet, tam - 1);
        printf("%d\n", quant);
    }

    return 0;
}