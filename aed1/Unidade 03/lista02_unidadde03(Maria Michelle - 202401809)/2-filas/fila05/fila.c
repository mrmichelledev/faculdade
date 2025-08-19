#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct fila {
    int inicio, final;
    chamada dados[MAX];
};

Fila* cria_Fila() {
    Fila *fi = (Fila*) malloc(sizeof(struct fila));
    if (fi != NULL) {
        fi->inicio = 0;
        fi->final = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi) {
    free(fi);
}

int insere_Fila(Fila* fi, chamada n) {
    if (fi == NULL || Fila_cheia(fi)) return 0;
    fi->dados[fi->final] = n;
    fi->final = (fi->final + 1) % MAX;
    return 1;
}

int remove_Fila(Fila* fi, chamada *nomeI) {
    if (fi == NULL || Fila_vazia(fi)) return 0;
    *nomeI = fi->dados[fi->inicio];
    fi->inicio = (fi->inicio + 1) % MAX;
    return 1;
}

int tamanho_Fila(Fila* fi) {
    if (fi == NULL) return -1;
    return (fi->final - fi->inicio + MAX) % MAX;
}

int Fila_cheia(Fila* fi) {
    if (fi == NULL) return -1;
    return ((fi->final + 1) % MAX == fi->inicio);
}

int Fila_vazia(Fila* fi) {
    if (fi == NULL) return -1;
    return (fi->inicio == fi->final);
}

int copia_Fila(Fila* f1, Fila* f2) {
    if (f1 == NULL || f2 == NULL || Fila_vazia(f1)) return 0;

    chamada temp;
    int i, tamanho = tamanho_Fila(f1);

    for (i = 0; i < tamanho; i++) {
        remove_Fila(f1, &temp);
        insere_Fila(f2, temp);
        insere_Fila(f1, temp);
    }

    return 1;
}

void imprime_Fila(Fila* f1, Fila* f2) {
    int tamanho1 = tamanho_Fila(f1);
    int tamanho2 = tamanho_Fila(f2);
    int i;

    printf("\n%-20s %-20s\n", "Fila 01", "Fila 02");
    printf("-----------------------------------------------\n");

    for (i = 0; i < tamanho1 || i < tamanho2; i++) {
        if (i < tamanho1) {
            printf("%-20s", f1->dados[(f1->inicio + i) % MAX].nome);
        } else {
            printf("%-20s", "");
        }

        if (i < tamanho2) {
            printf("%-20s\n", f2->dados[(f2->inicio + i) % MAX].nome);
        } else {
            printf("\n");
        }
    }
}
