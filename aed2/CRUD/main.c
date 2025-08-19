#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crud.h"

int main() {
    Lista* al = cria_lista();
    aluno aluno, temp;
    int opcao, matricula;
    char nome[30];

    do {
        printf("\n====== MENU CRUD ALUNOS ======\n");
        printf("1 - Inserir aluno\n");
        printf("2 - Consultar aluno\n");
        printf("3 - Atualizar dados\n");
        printf("4 - Excluir aluno\n");
        printf("5 - Imprimir lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("Digite a matricula: ");
                scanf("%d", &aluno.matricula);
                getchar();

                printf("Digite o nome: ");
                fgets(aluno.nome, 30, stdin);
                aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

                if (insere_aluno(al, aluno))
                    printf("Aluno inserido com sucesso.\n");
                else
                    printf("Erro ao inserir aluno.\n");
                break;

            case 2:
                printf("Digite a matricula para consulta: ");
                scanf("%d", &matricula);

                if (consulta_aluno(al, matricula, &aluno)) {
                    printf("Aluno encontrado:\n");
                    printf("Matricula: %d\n", aluno.matricula);
                    printf("Nome: %s\n", aluno.nome);
                } else {
                    printf("Aluno nao encontrado.\n");
                }
                break;

            case 3:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                getchar();

                printf("Digite o novo nome: ");
                fgets(aluno.nome, 30, stdin);
                aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
                aluno.matricula = matricula;

                if (atualiza_aluno(al, matricula, aluno))
                    printf("Dados atualizado com sucesso.\n");
                else
                    printf("Aluno nao encontrado.\n");
                break;

            case 4:
                printf("Digite o nome do aluno para excluir: ");
                fgets(nome, 30, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                strcpy(temp.nome, nome);

                if (exclui_aluno(al, temp))
                    printf("Aluno excluido com sucesso.\n");
                else
                    printf("Aluno nao encontrado.\n");
                break;

            case 5:
                imprime_aluno(al);
                break;

            case 0:
                libera_lista(al);
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}