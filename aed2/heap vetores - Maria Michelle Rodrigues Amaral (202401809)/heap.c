#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "heap.h"

void criaHeap(heap* he) {
    he->tam = 0;
}

int pai(int i){
    return (i - 1) / 2;
}

int filhoEsquerda(int i){
    return 2 * i + 1;
}

int filhoDireita(int i){
    return 2 * i + 2;
}

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void insere(heap* he, int num){
    if(he->tam == MAX){
        printf("ERRO, heap cheia!\n");
        return;
    }

    he->vet[he->tam] = num;

    int i = he->tam;
    while(i != 0 && he->vet[pai(i)] < he->vet[i]){
        swap(&he->vet[pai(i)], &he->vet[i]);
        i = pai(i);
    }

    he->tam++;
}

void maxHeapify(heap* he, int i){
    int max = i;
    int esq = filhoEsquerda(i);
    int dir = filhoDireita(i);

    if(esq < he->tam && he->vet[esq] > he->vet[max])
        max = esq;

    if(dir < he->tam && he->vet[dir] > he->vet[max])
        max = dir;

    if(max != i){
        swap(&he->vet[i], &he->vet[max]);
        maxHeapify(he, max);
    }
}

void remover(heap* he){
    if(he->tam == 0){
        printf("ERRO, heap vazia!\n");
        return;
    }

    he->vet[0] = he->vet[he->tam - 1];
    he->tam--;
    maxHeapify(he, 0);
}

void consulta(heap* he, int num){
    int i, pos = -1;
    for(i = 0; i < he->tam; i++){
        if(he->vet[i] == num){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        printf("O valor digitado nao existe!\n");
        return;
    }

    int p = pai(pos);
    int filhoE = filhoEsquerda(pos);
    int filhoD = filhoDireita(pos);

    if (pos != 0)
        printf("Pai: %d\n", he->vet[p]);
    else
        printf("Elemento pai.\n");

    if (filhoE < he->tam)
        printf("Filho esquerdo (<-): %d\n", he->vet[filhoE]);
    else
        printf("S/ filho esquerdo\n");

    if (filhoD < he->tam)
        printf("Filho direito (->): %d\n", he->vet[filhoD]);
    else
        printf("S/ filho direito\n");
}

//optei por fazer uma impressão visual, para isso eu usei o auxilio do chatgpt
void imprime(heap* he) {
    if (he->tam == 0) {
        printf("Heap vazia.\n");
        return;
    }

    int j, k, l, i = 0;           
    int nivel = 0;       
    int elementos = 1;   

    // Calcula a profundidade máxima da heap com base no número de elementos
    int profundidade = 0;
    int total = he->tam;
    while ((1 << profundidade) <= total) {
        profundidade++;
    }

    while (i < he->tam) {
        // Cálculo do espaçamento com base na profundidade total da árvore
        int espacamento = (1 << (profundidade - nivel));

        // Espaço inicial antes do primeiro número do nível
        for (j = 0; j < espacamento; j++) printf(" ");

        // Imprime os números do nível atual
        for (j = 0; j < elementos && i < he->tam; j++, i++) {
            printf("%2d", he->vet[i]);

            // Espaço entre os nós
            for (k = 0; k < (espacamento * 2 - 2); k++) printf(" ");
        }
        printf("\n");

        // Imprime os ramos (se houver filhos)
        if (i < he->tam) {
            int qtdRamos = elementos;

            // 2 linhas de ramos
            for (l = 1; l <= 2; l++) {
                for (j = 0; j < espacamento - l; j++) printf(" ");

                for (j = 0; j < qtdRamos && (i - qtdRamos + j) < he->tam; j++) {
                    printf("/");

                    for (k = 0; k < (l * 2 - 1); k++) printf(" ");

                    printf("\\");

                    for (k = 0; k < (espacamento * 2 - 2 * l - 1); k++) printf(" ");
                }
                printf("\n");
            }
        }

        nivel++;
        elementos *= 2;
    }
}