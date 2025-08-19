#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cubo.h"

int main(){
    float aresta;
    Cubo* varA;

    printf("Digite o valor da aresta do cubo: ");
    scanf("%f", &aresta);

    varA = cubo_cria(aresta);

    printf("Tamanho de cada lado do cubo = %.2f\n", cubo_acessa(varA));
    printf("Area da face do cubo = %.2f\n", cubo_areaFace(varA));
    printf("Area total do cubo = %.2f\n", cubo_areaTotal(varA));
    printf("Volume = %.2f\n", cubo_volume(varA));

    cubo_libera(varA);

    return 0;
}