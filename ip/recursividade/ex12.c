#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int pxElemento(int vet[], int tam, int teste, int cont){
    int i;
    if(tam < 0) 
        return teste;
    
    for(i = cont; i < tam; i++){
        if(vet[i] * 10 == vet[i+1]){
            teste = 1;
            break;
        }else{
            teste = 0;
        }
    }
    
    return pxElemento(vet, tam-1, teste, cont+1);
}

int main() {
    int i, j, teste, num, *vet, cont = 0, te = 0;
    vet = (int*)malloc(30 * sizeof(int));
    scanf("%d", &teste);
    
    for(i = 0; i < teste; i++){
        scanf("%d", &num);
        
        for(j = 0; j < num; j++)
            scanf("%d", &vet[j]);
        
        
        if(pxElemento(vet, num, te, cont))
            printf("VERDADEIRO\n");
        else
            printf("FALSO\n");
    }
    
    free(vet);

    return 0;
}