#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int var1 = 52, var2 = 33;
    int *ptr1 = &var1;
    int *ptr2 = &var2;
    
    if(ptr1 > ptr2)
        printf("Endereco variavel 1 %d e maior que o endereco da variavel 2 %d", ptr1, ptr2);
    else
        printf("Endereco variavel 2 %d e maior que o endereco da variavel 1 %d", ptr2, ptr1);

    return 0;
}
