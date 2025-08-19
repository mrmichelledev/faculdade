#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cilindro.h"

struct cilindro{
    float raio;
    float altura;
};

//cria cilindro
Cilindro* cilindro_cria(float raio, float altura){
    Cilindro* c = (Cilindro*) malloc(sizeof(Cilindro));
    if(c != NULL){
        c->raio = raio;
        c->altura = altura;
    }
    return c;
}

//libera cilindro
void cilindro_libera(Cilindro* c){
    if(c != NULL){
        free(c);
    }
}

//acessa raio
float cilindro_acessaR(Cilindro* c) {
    return c->raio;
}

//acessa altura
float cilindro_acessaA(Cilindro* c) {
    return c->altura;
}

//area
float cilindro_area(Cilindro* c) {
    return 2 * M_PI * c->raio * (c->raio + c->altura);
}

//volume cilindro
float cilindro_volume(Cilindro* c) {
    return M_PI * c->raio * c->raio * c->altura;
}
