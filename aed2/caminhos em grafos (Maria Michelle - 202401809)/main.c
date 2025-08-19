#include <stdio.h>
#include "grafos.h"

int main(){
    char origemChar, destinoChar;

    int matriz[VERTICE][VERTICE] = {
        {0, 4, 8, INF, INF},
        {4, 0, 1, 1, INF},
        {8, INF, 0, 4, 2},
        {INF, 2, 4, 0, 7},
        {INF, INF, 2, 7, 0}
    };

    Grafos g;

    insere(&g, matriz);

    printf("\nMatriz de distancias antes do algoritmo:\n");
    imprime(&g);

    floydWarshall(&g);

    printf("\nMatriz de distancias depois de Floyd-Warshall:\n");
    imprime(&g);

    printf("\nDigite a origem e o destino (A a E): ");
    scanf(" %c %c", &origemChar, &destinoChar);

    printf("\nMenor caminho de %c para %c:\n", origemChar, destinoChar);
    consultaCaminho(&g, origemChar, destinoChar);

    return 0;
}
