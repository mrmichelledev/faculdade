#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int numMatricula;
    char  nome[50];
    double n1;
    double n2;
    double n3;
} dados;

int main(){
    printf("a estrutura tem %d bytes", sizeof(dados));

    return 0;
}
