#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pr(char palavra[], int tam){
    int i;
    if (tam == 0)
        return;
   
    for( i = 0; i < tam; i++){
        printf("%c", palavra[i]);
    }
    
    printf("\n");
    
    pr(palavra, tam - 1);
}

int main() {
    int i, j, num;
    char *palavra;
    scanf("%d\n", &num);
    
    palavra = (char*)malloc(300 * sizeof(char));
    
    for(i = 0; i < num; i++){
        fgets(palavra, sizeof(palavra), stdin);
        
        printf("Caso de teste %d\n", i + 1);
        pr(palavra, strlen(palavra) - 1);
    }

    return 0;
}