#include <stdio.h>
#include <stdbool.h>
#include "verificador.h"

int main() {
    char nome_arquivo[100];
    FILE *arquivo;

    printf("Informe o nome do arquivo fonte C: ");
    scanf("%s", nome_arquivo);

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    Pilha p;
    iniciaPilha(&p);

    char linha[MAX_LINHA];
    int numLinha = 0;
    bool in_string = false, in_char = false;

    while (fgets(linha, MAX_LINHA, arquivo)) {
        numLinha++;
        verificaLinha(linha, numLinha, &p, &in_string, &in_char);
    }

    if (!in_string && !in_char) {
        if (!pilhaVazia(&p)) {
            char topo;
            TipoToken tipo;

            while (pop(&p, &topo, &tipo))
                printf("Erro final: '%c' aberto sem fechamento\n", topo);
            
        } else
            printf("Analise de sintaxe concluida com sucesso.\n");
            
        
    } else printf("Erro final: aspas nao fechadas.\n");
    

    fclose(arquivo);
    return 0;
}
