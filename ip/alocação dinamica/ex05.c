#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codCurso;
    double valCredito;
    char nomeCurso[100];
} tabela;

typedef struct{
    char nomeAluno[500];
    int codMatricula;
    int numCredito;
} registro;

void gerarBoleto(tabela *infoCursos, registro *infoAlunos, int tam1, int tam2){
    int i, j;
    double mensalidade;

    for(i = 0; i < tam2; i++){
        mensalidade = 0;

        for(j = 0; j < tam1; j++){
            if(infoAlunos[i].codMatricula == infoCursos[j].codCurso){
                mensalidade = infoCursos[j].valCredito * infoAlunos[i].numCredito;
                printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2lf Mensalidade: %.2lf\n", infoAlunos[i].nomeAluno, infoCursos[j].nomeCurso, infoAlunos[i].numCredito, infoCursos[j].valCredito, mensalidade);
                break;
            }
        }
    }
}

int main(){
    int n, m, i;
    scanf("%d", &n);
    tabela *infoCursos = (tabela*) malloc(n * sizeof(tabela));

    for(i = 0; i < n; i++){
        scanf("%d %lf", &infoCursos[i].codCurso, &infoCursos[i].valCredito);
        getchar();
        fgets(infoCursos[i].nomeCurso, 100, stdin);
        infoCursos[i].nomeCurso[strcspn(infoCursos[i].nomeCurso, "\n")] = '\0'; 
    }

    scanf("%d", &m);
    getchar();
    registro *infoAlunos = (registro*) malloc(m * sizeof(registro));
    
    for(i = 0; i < m; i++){
        fgets(infoAlunos[i].nomeAluno, 500, stdin);
        infoAlunos[i].nomeAluno[strcspn(infoAlunos[i].nomeAluno, "\n")] = '\0';
        scanf("%d %d", &infoAlunos[i].codMatricula, &infoAlunos[i].numCredito);
        getchar();
    }

    gerarBoleto(infoCursos, infoAlunos, n, m);

    free(infoCursos);
    free(infoAlunos);
    return 0;
}