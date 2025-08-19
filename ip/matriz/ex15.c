#include <stdio.h>

#define MAX_SIZE 10

void imprimirEmEspiral(int matriz[MAX_SIZE][MAX_SIZE], int linhas, int colunas) {
    int i, inicioLinha = 0, inicioColuna = 0;

    while (inicioLinha < linhas && inicioColuna < colunas) {
        // Imprimir a primeira linha da camada restante da esquerda para a direita
        for (i = inicioColuna; i < colunas; ++i) {
            printf("%d ", matriz[inicioLinha][i]);
        }
        inicioLinha++;

        // Imprimir a última coluna da camada restante de cima para baixo
        for (i = inicioLinha; i < linhas; ++i) {
            printf("%d ", matriz[i][colunas - 1]);
        }
        colunas--;

        // Imprimir a última linha da camada restante da direita para a esquerda
        if (inicioLinha < linhas) {
            for (i = colunas - 1; i >= inicioColuna; --i) {
                printf("%d ", matriz[linhas - 1][i]);
            }
            linhas--;
        }

        // Imprimir a primeira coluna da camada restante de baixo para cima
        if (inicioColuna < colunas) {
            for (i = linhas - 1; i >= inicioLinha; --i) {
                printf("%d ", matriz[i][inicioColuna]);
            }
            inicioColuna++;
        }
    }
}

int main() {
    int matriz[MAX_SIZE][MAX_SIZE];
    int linhas, colunas;
    int i, j;

    // Leitura das dimensões da matriz
    scanf("%d %d", &linhas, &colunas);

    // Verificação se as dimensões são válidas
    if (linhas <= 0 || linhas > MAX_SIZE || colunas <= 0 || colunas > MAX_SIZE) {
        printf("Dimensao invalida\n");
        return 1;
    }

    // Leitura dos elementos da matriz
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Impressão da matriz em ordem espiral
    imprimirEmEspiral(matriz, linhas, colunas);
    printf("\n");

    return 0;
}
