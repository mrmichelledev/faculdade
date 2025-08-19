#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main(){
    float d;
    Ponto *pontoA,*pontoB;
    float a = 0, b = 0;

    // Cria os pontos
    pontoA = pto_cria(10,21);
    pontoB = pto_cria(7,25);

    //Acessa os valores os pontos criados
    printf("Valores dos pontos antes \"a\" e \"b\": %.2f -- %.2f\n", a, b);
    pto_acessa(pontoA, &a, &b);
    printf("Valores dos pontos depois \"a\" e \"b\": %.2f -- %.2f\n", a, b);


    // Distância com os valores definidos na criação dos pontos
    d = pto_distancia(pontoA,pontoB);
    printf("Distancia entre pontos: %.2f\n",d);


    // Distância após a modificação dos valores do ponto pontoB
    pto_atribui(pontoB, 1, 1);
    d = pto_distancia(pontoA,pontoB);
    printf("Distancia entre pontos: %.2f\n",d);

    // Desalocação da memória usada
    pto_libera(pontoB);
    pto_libera(pontoA);

    return 0;
}
