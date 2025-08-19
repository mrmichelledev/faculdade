#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cilindro Cilindro;

Cilindro* cilindro_cria(float raio, float altura);
void cilindro_libera(Cilindro* c);
float cilindro_acessaR(Cilindro* c);
float cilindro_acessaA(Cilindro* c);
float cilindro_area(Cilindro* c);
float cilindro_volume(Cilindro* c);