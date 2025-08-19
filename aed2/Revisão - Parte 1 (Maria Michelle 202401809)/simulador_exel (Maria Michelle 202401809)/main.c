#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registro.h"

int main(){
    FILE* lista = fopen("alunoss.txt", "rt");
    if (lista == NULL) {
        printf("ERROR!\n");
        return 1;
    }

    Lista* li = cria_lista();
    aluno al;

    while (fscanf(lista, "%s %f %f %d", al.nome, &al.n1, &al.n2, &al.frequencia) != EOF)
        insere_aluno(li, al);

    printf("\nArquivo lido com sucesso!\n\n");

    media_aluno(li);
    situacao_aluno(li);
    
    imprime_lista(li);

    libera_lista(li);

    fclose(lista);

    return 0;
}