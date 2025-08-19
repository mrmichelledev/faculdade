#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool palindromo(char vet[], int inicio, int fim) {
    if (inicio >= fim)
        return true;
    
    if (vet[inicio] != vet[fim])
        return false;
        
    return palindromo(vet, inicio + 1, fim - 1);
}

int main() {
    int i, j, num, tam;
    char vet[2000];
    
    scanf("%d", &num);
    getchar(); // Para consumir o '\n' após o número de testes

    for (j = 0; j < num; j++) {
        scanf("%d", &tam);
        getchar(); // Para consumir o '\n' após o número de caracteres

        for (i = 0; i < tam; i++) {
            do {
                vet[i] = getchar();
            } while (vet[i] == ' '); // Ignorar espaços
        }

        vet[tam] = '\0'; // Adiciona o terminador nulo para tratar como string

        if (palindromo(vet, 0, tam - 1))
            printf("PALINDROMO\n");
        else
            printf("NAO PALINDROMO\n");
    }

    return 0;
}
