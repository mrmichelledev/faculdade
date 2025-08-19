#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int x;
    int y;
} coo;

typedef struct{
    coo posA;
    coo posB;
} Ponto;

int main(){
    Ponto coordenadas;

    printf("digite as coordenadas de PA(x, y):");
    scanf("%d %d", &coordenadas.posA.x, &coordenadas.posA.y);

    printf("digite as coordenadas de PB(x, y):");
    scanf("%d %d", &coordenadas.posB.x, &coordenadas.posB.y);

    double disX = pow((coordenadas.posB.x - coordenadas.posA.x), 2);
    double disY = pow((coordenadas.posB.y - coordenadas.posA.y), 2);

    double distancia = sqrt(disX + disY);

    printf("A distancia entre os pontos PA e PB = %.2lf", distancia);


    return 0;
}
