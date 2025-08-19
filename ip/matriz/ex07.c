#include <stdio.h>

int main() {
    int matriz[6][6], i, j, soma, maiorSoma = -1000; // Inicializar maiorSoma com um valor muito baixo

    // Leitura da matriz de entrada
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Percorrer todas as possíveis ampulhetas na matriz
    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 3; j++) {
            // Calcular a soma da ampulheta com centro em (i, j)
            soma = matriz[i][j] + matriz[i][j+1] + matriz[i][j+2]
                               + matriz[i+1][j+1]
                 + matriz[i+2][j] + matriz[i+2][j+1] + matriz[i+2][j+2];
            
            // Verificar se encontramos uma nova maior soma
            if (soma > maiorSoma) {
                maiorSoma = soma;
            }
        }
    }

    // Imprimir o resultado da maior soma encontrada
    printf("%d\n", maiorSoma);

    return 0;
}
