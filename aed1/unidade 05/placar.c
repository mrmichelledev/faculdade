#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[21];
    int problemas;
} Alunos;

void swap(Alunos *a, Alunos *b){
    Alunos aux = *a;
    *a = *b;
    *b = aux;
}

void ordena(Alunos *alunos, int tamanho){
    int i, j;

    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - i - 1; j++){
            if(alunos[j].problemas < alunos[j + 1].problemas || 
              (alunos[j].problemas == alunos[j + 1].problemas && 
               strcmp(alunos[j].nome, alunos[j + 1].nome) > 0)){
                swap(&alunos[j], &alunos[j + 1]);
            }
        }
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    Alunos alunos[n];

    for(i = 0; i < n; i++)
        scanf("%s %d", alunos[i].nome, &alunos[i].problemas);

    printf("\n");
    ordena(alunos, n);

    for(i = 0; i < n; i++){
        printf("%s %d", alunos[i].nome, alunos[i].problemas);

        if(i == n - 1)
            printf(" #reprovado(a)");

        printf("\n");
    }

    return 0;
}
