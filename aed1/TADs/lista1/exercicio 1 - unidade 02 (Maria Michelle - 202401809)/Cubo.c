#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cubo.h"

struct cubo{
    float a;
};

//cria cubo
Cubo* cubo_cria(float a){
    Cubo* c = (Cubo*) malloc(sizeof(Cubo));
    if(c != NULL){
        c->a = a;
    }
    return (c);
}

//libera cubo
void cubo_libera(Cubo* c){
    if(c != NULL){
        free(c);
    }
}

//acessa cubo
float cubo_acessa(Cubo* c){
    return (c->a);
}

//atribui um valor a aresta
void cubo_atribui(Cubo* c, float a){
    if(c != NULL){
        c->a = a;
    }
}

//area da face do cubo
float cubo_areaFace(Cubo* c){
    if (c != NULL){
        return pow(c->a, 2);
    }
}

//area total do cubo
float cubo_areaTotal(Cubo* c){
    if (c != NULL){
        return 6 * pow(c->a, 2);
    }
}

//volume cubo
float cubo_volume(Cubo* c){
    if (c != NULL){
        return pow(c->a, 3);
    }
}