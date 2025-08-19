#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N < 1 || N > 1000) {
        printf("Quantidade de elementos fora do intervalo permitido.\n");
        return 1;
    }

    int numeros[N];
    int i;

    // Leitura dos números inteiros em ordem crescente
    for (i = 0; i < N; i++) {
        scanf("%d", &numeros[i]);
    }

    // Impressão dos elementos únicos
    for (i = 0; i < N; i++) {
        // Verifica se é o primeiro elemento ou se é diferente do anterior
        if (i == 0 || numeros[i] != numeros[i - 1]) {
            printf("%d\n", numeros[i]);
        }
    }

    return 0;
}
