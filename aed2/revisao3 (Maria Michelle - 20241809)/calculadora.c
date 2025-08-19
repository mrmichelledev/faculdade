#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculadora.h"

struct elemento {
    float valor;
    struct elemento* prox;
};

typedef struct elemento Elem;

Pilha* cria_pilha() {
    Pilha* pi = malloc(sizeof(Pilha));

    if (pi != NULL) *pi = NULL;
    return pi;
}

void libera_pilha(Pilha* pi) {
    if (pi != NULL) {
        Elem* no;

        while ((*pi) != NULL) {
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }

        free(pi);
    }
}

int empilha(Pilha* pi, float num) {
    if (pi == NULL) return 0;

    Elem* no = malloc(sizeof(Elem));
    if (no == NULL) return 0;

    no->valor = num;
    no->prox = *pi;
    *pi = no;

    return 1;
}

int desempilhar(Pilha* pi, float* valor) {
    if (pi == NULL || *pi == NULL) return 0;

    Elem* remov = *pi;
    *valor = remov->valor;
    *pi = remov->prox;
    free(remov);

    return 1;
}

float calcula(float a, float b, char x) {
    switch(x) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0.0;
    }
}

float resolver_expressao(Pilha* pi, char x[]) {
    char *pt = strtok(x, " ");
    float num, n1, n2;

    while (pt) {
        if (pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*') {
            if (!desempilhar(pi, &n1)) return 0.0;
            if (!desempilhar(pi, &n2)) return 0.0;

            num = calcula(n2, n1, pt[0]);
            empilha(pi, num);

        } else {
            num = strtof(pt, NULL);
            empilha(pi, num);
        }

        pt = strtok(NULL, " ");
    }

    if (desempilhar(pi, &num)) return num;

    return 0.0;
}
