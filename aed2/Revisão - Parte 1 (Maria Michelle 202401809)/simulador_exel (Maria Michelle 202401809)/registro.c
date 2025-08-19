#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registro.h"

struct elemento{
    aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL)
        *li = NULL;

    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;

        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }

        free(li);
    }
}

void insere_aluno(Lista* li, aluno al){
    if(li == NULL)
        return;

    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL)
        return;

    no->dados = al;
    no->prox = NULL;
    
    if((*li) == NULL){
        *li = no;
    }else{
        Elem *aux;
        aux = *li;

        while(aux->prox != NULL)
            aux = aux->prox;

        aux->prox = no;
    }
} 

void media_aluno(Lista* li){
    if (li == NULL)
        return;

    Elem* no = *li;

    while (no != NULL) {
        no->dados.media = (no->dados.n1 + no->dados.n2) / 2;
        no = no->prox;
    }
}


float media_geral(Lista* li){
    if (li == NULL)
        return 0;

    float soma = 0;
    int contador = 0;

    Elem* no = *li;

    while (no != NULL) {
        soma += no->dados.media;
        contador++;
        no = no->prox;
    }

    if (contador > 0)
        return soma / contador;

    return 0;
}

void situacao_aluno(Lista* li){
    if (li == NULL)
        return;

        Elem* no = *li;
        aprovados = 0;
        reprovados = 0;

        while (no != NULL) {
            if (no->dados.media < 6 || no->dados.frequencia < 75){
                strcpy(no->dados.situacao, "REPROVADO(A)");
                reprovados++;
            } else{
                strcpy(no->dados.situacao, "APROVADO(A)");
                aprovados++;  
            }
    
            no = no->prox;
        }
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;

    Elem* no = *li;
    int i = 1;

    printf("> Dados finais\n");
    printf("  Media geral da turma: %.1f  |  Alunos Aprovados: %d  |  Alunos Reprovados: %d\n\n\n", media_geral(li), aprovados, reprovados);

    printf("            A       |   B   |   C   |   D   |   E   |       F\n");
    printf("  0      sequencia      N1      N2      FQ      MF         SIT\n");

    while(no != NULL){
        if(i < 10) printf("  %d      %s          %.1f     %.1f     %d      %.1f     %s\n", i, no->dados.nome, no->dados.n1, no->dados.n2, no->dados.frequencia, no->dados.media, no->dados.situacao);
        else printf("  %d     %s         %.1f     %.1f     %d      %.1f     %s\n", i, no->dados.nome, no->dados.n1, no->dados.n2, no->dados.frequencia, no->dados.media, no->dados.situacao);

        i++;
        no = no->prox;
    }
}