/*
Inclua as funções de inicializações necessárias e as operações que retornem os tamanhos de cada lado, a sua área e o seu volume.
    1 - criar o cubo
    2 - retornar o comprimento da aresta
    3 - retornar a area de uma face do cubo
    4 - retornar a area total do cubo
    5 - retornar o volume do cubo
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cubo Cubo;

Cubo* cubo_cria(float a);
void cubo_libera(Cubo* c);
float cubo_acessa(Cubo* c);
void cubo_atribui(Cubo* c, float a);
float cubo_areaFace(Cubo* c);
float cubo_areaTotal(Cubo* c);
float cubo_volume(Cubo* c);