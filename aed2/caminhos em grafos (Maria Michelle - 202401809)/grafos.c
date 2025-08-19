#include <stdio.h>
#include "grafos.h"

void insere(Grafos* g, int elem[VERTICE][VERTICE]){
    int i, j;
    g->numV = VERTICE;

    for(i = 0; i < VERTICE; i++){
        for(j = 0; j < VERTICE; j++){
            g->dist[i][j] = elem[i][j];
            if(i != j && elem[i][j] != INF)
                g->next[i][j] = j;
            else
                g->next[i][j] = -1;
        }
    }
}

void floydWarshall(Grafos* g){
    int i, j, k;
    for(k = 0; k < VERTICE; k++){
        for(i = 0; i < VERTICE; i++){
            for(j = 0; j < VERTICE; j++){
                if(g->dist[i][k] + g->dist[k][j] < g->dist[i][j]){
                    g->dist[i][j] = g->dist[i][k] + g->dist[k][j];
                    g->next[i][j] = g->next[i][k];
                }
            }
        }
    }
}

void consultaCaminho(Grafos* g, char origemChar, char destinoChar){
    int origem = origemChar - 'A';
    int destino = destinoChar - 'A';

    if(origem < 0 || origem >= VERTICE || destino < 0 || destino >= VERTICE){
        printf("Vertices invalidos.\n");
        return;
    }

    if(g->next[origem][destino] == -1){
        printf("Nao existe caminho de %c para %c\n", origemChar, destinoChar);
        return;
    }

    printf("\t%c", origemChar);
    int atual = origem;

    while(atual != destino){
        atual = g->next[atual][destino];
        printf(" -> %c", atual + 'A');
    }

    printf("\n");
}

void imprime(Grafos* g){
    int i, j;

    printf("    ");

    for (j = 0; j < VERTICE; j++)
        printf("  %c ", 'A' + j);

    printf("\n");

    for(i = 0; i < VERTICE; i++){
        printf(" %c ", 'A' + i);

        for(j = 0; j < VERTICE; j++){
            if(g->dist[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", g->dist[i][j]);
        }

        printf("\n");
    }
}