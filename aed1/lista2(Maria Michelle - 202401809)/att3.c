#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int x;
    int y;
} coo;

int main(){
    coo coordenadas;

    printf("digite as coordenadas de um ponto qualquer (x, y):");
    scanf("%d %d", &coordenadas.x, &coordenadas.y);

    double distancia = sqrt(pow(coordenadas.x, 2) + pow(coordenadas.y, 2));

    printf("A distancia entre os pontos P1 e P0(origem) %.2lf", distancia);


    return 0;
}

