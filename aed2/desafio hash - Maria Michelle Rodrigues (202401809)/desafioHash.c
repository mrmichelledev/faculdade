#include <stdio.h>
#include "hash.h"

int main() {
    Hash* h = criaHash();
    Dados d;
    int res, passos;

    FILE* arq = fopen("lista.txt", "r");
    if (!arq) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    printf("\nInserindo dados na tabela hash...\n");

    while (fscanf(arq, "%d %[^\n]\n", &d.cod, d.nome) == 2) {
        inserir(h, d);
    }

    fclose(arq);

    printf(CINZA "\nInsercao concluida.\n" RESET);

    printf("\nBUSCAR CHAVE:\n");
    while(1) {
        printf(CINZA "\n[!] Caso queira usar uma chave valida, confira o arquivo ""lista.txt"" [!]\n\n" RESET);
        printf("Digite o codigo para buscar (-1 para encerrar e vizualizar os dados finais): ");
        scanf("%d", &i);
        if (i == -1) break;

        res = buscar(h, i, &d, &passos);
        if (res) {
            printf(CINZA "Chave %d | quantidade de passos -> %d\n\n" RESET, i, passos);
        } else {
            printf(CINZA "Chave %d | quantidade de passos -> %d (nao encontrada)\n\n" RESET, i, passos);
        }
    }

    analiseFinal(h);
    liberaHash(h);

    return 0;
}