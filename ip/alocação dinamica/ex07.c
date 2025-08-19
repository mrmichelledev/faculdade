#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codCurso;
    double valCredito;
    char **nomeCurso;
} tabela;

typedef struct{
    char **nomeAluno;
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
    char buffer[1000];
    scanf("%d", &n);
    tabela *infoCursos = (tabela*) malloc(n * sizeof(tabela));

    for(i = 0; i < n; i++){
        scanf("%d %lf", &infoCursos[i].codCurso, &infoCursos[i].valCredito);
        getchar();

        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; 
        infoCursos[i].nomeCurso = (tabela*)malloc((strlen(buffer) + 1) * sizeof(tabela));
        strcpy(infoCursos[i].nomeCurso, buffer);
    }

    scanf("%d", &m);
    getchar();
    registro *infoAlunos = (registro*) malloc(m * sizeof(registro));
    
    for(i = 0; i < m; i++){
        fgets(buffer, 500, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        infoAlunos[i].nomeAluno = (registro*)malloc((strlen(buffer) + 1) * sizeof(registro));
        strcpy(infoAlunos[i].nomeAluno, buffer);

        scanf("%d %d", &infoAlunos[i].codMatricula, &infoAlunos[i].numCredito);
        getchar();
    }

    gerarBoleto(infoCursos, infoAlunos, n, m);

    for(i = 0; i < n; i++)
        free(infoCursos[i].nomeCurso);

    for(i = 0; i < m; i++)
        free(infoAlunos[i].nomeAluno);

    free(infoCursos);
    free(infoAlunos);
    return 0;
}