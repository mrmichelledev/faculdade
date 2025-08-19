#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, i;

    do{
        printf("Digite um valor inteiro nao negativo: ");
        scanf("%d", &n);

        if(n < 1)
            printf("Numero invalido!\n");
        
    } while(n < 1);

    int *v = (int*) malloc(n * sizeof(int));

    printf("Digite numeros inteiros >= 2: ");
    for(i = 0; i < n; i++){
        do{    
            scanf("%d", &v[i]);

            if(v[i] < 2)
                printf("Numero invalido!\n");

        } while(v[i] < 2);
        
    }

    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    free(v);

    return 0;
}
