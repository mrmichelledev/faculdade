#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

/*2º Será aprovado na disciplina ou no eixo temático/módulo o estudante que obtiver
nota final igual ou superior a seis vírgula zero (6,0) e frequência igual ou superior a setenta e
cinco por cento (75%) da carga horária da disciplina ou do eixo temático/módulo, observado
o disposto no artigo 83.*/

typedef struct {
    char nome[30]; 
    float nota; 
    int frequencia;
} Dados;

int main(){
    Dados alunos[MAX];
    int i, aprovados=0, reprovados=0;
    float notas = 0, mediaGeral;

    FILE* lista = fopen("alunos.txt", "rt");

    if (lista == NULL){
        printf("ERROR!\n");
        return 1;
    }

    printf("> Info alunos:\n Por favor, preencha as informacoes seguindo a seguinte ordem: Nome, Nota e Frequencia (%%).\n");

    for(i = 0; i < MAX; i++){
        fscanf(lista, "%s", alunos[i].nome);
        fscanf(lista, "%f", &alunos[i].nota);
        fscanf(lista, "%d", &alunos[i].frequencia);

        notas += alunos[i].nota;
        
        if(alunos[i].nota < 6 || alunos[i].frequencia < 75)
            reprovados++;
        else
            aprovados++;
            
    }

    printf("\nArquivo lido com sucesso!\n\n");
    fclose(lista);

    mediaGeral = notas/30;

    printf("> Dados finais\n");
    printf("Media geral da turma: %.1f\nAlunos Aprovados %d\nAlunos Reprovados %d\n\n", mediaGeral, aprovados, reprovados);

    for(i = 0; i < MAX; i++){
        if(alunos[i].nota < 6 && alunos[i].frequencia < 75)
            printf("%s %.1f %d REPROVADO(A) POR NOTA E FREQUENCIA\n", alunos[i].nome, alunos[i].nota, alunos[i].frequencia);
        else if (alunos[i].nota < 6)
            printf("%s %.1f %d REPROVADO(A) POR NOTA\n", alunos[i].nome, alunos[i].nota, alunos[i].frequencia);
        else if (alunos[i].frequencia < 75)
            printf("%s %.1f %d REPROVADO(A) POR FREQUENCIA\n", alunos[i].nome, alunos[i].nota, alunos[i].frequencia);
        
        printf("%s %.1f %d\n", alunos[i].nome, alunos[i].nota, alunos[i].frequencia);
    }

    return 0;
}