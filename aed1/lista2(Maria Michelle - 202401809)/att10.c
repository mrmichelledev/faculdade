#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int var1;
    int var2;

    printf("digite dois valores: ");
    scanf("%d", &var1);
    scanf("%d", &var2);

    int *ptr1 = &var1;
    int *ptr2 = &var2;
    
    if(ptr1 > ptr2)
        printf("Endereco variavel 1 %p e maior que o endereco da variavel 2 %p", (void *)ptr1, (void *)ptr2);
    else
        printf("Endereco variavel 2 %p e maior que o endereco da variavel 1 %p", (void *)ptr2, (void *)ptr1);

    return 0;
}
