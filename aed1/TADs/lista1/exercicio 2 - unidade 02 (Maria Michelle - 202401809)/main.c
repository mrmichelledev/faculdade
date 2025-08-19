#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cilindro.h"

int main(){
    float raio;
    float altura;
    
    Cilindro* c;

    printf("Digite o valor do raio do cilindro: ");
    scanf("%f", &raio);
    printf("Digite o valor da altura do cilindro: ");
    scanf("%f", &altura);

    c = cilindro_cria(raio, altura);

    printf("Raio: %.2f\n", cilindro_acessaR(c));
    printf("Altura: %.2f\n", cilindro_acessaA(c));
    printf("Área superficial: %.2f\n", cilindro_area(c));
    printf("Volume: %.2f\n", cilindro_volume(c));

    cilindro_libera(c);

    return 0;
}