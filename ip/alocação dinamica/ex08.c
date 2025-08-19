#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int numMatric;
    int diaNsc;
    int mesNsc;
    int anoNsc;
    char *nome;
} dados;

int comparaDataNasc(dados aluno1, dados aluno2){
    if(aluno1.anoNsc < aluno2.anoNsc){
        return 1;
    }else if(aluno1.anoNsc == aluno2.anoNsc && aluno1.mesNsc < aluno2.mesNsc){
        return 1;
    } else if(aluno1.mesNsc == aluno2.mesNsc && aluno1.diaNsc < aluno2.diaNsc){
        return 1;
    }

    return 0;
}

void ordenar(dados *matricula, int tam){
    int i, j; dados aux;

    for(i = 0; i < tam - 1; i++){
        for(j = 0; j < tam - i - 1; j++){
            if(comparaDataNasc(matricula[j], matricula[j+ 1]) == 1){
                aux = matricula[j];
                matricula[j] = matricula[j + 1];
                matricula[j + 1] = aux;
            }
        }
    }
}

int main(){
    int num, i; char buffer[200];
    scanf("%d", &num);
    getchar();

    dados *matricula = (dados*)malloc(num * sizeof(dados));

    for(i = 0; i < num; i++){
        scanf("%d %d %d %d", &matricula[i].numMatric, &matricula[i].diaNsc, &matricula[i].mesNsc, &matricula[i].anoNsc);
        getchar();

        fgets(buffer, 200, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        
        matricula[i].nome = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(matricula[i].nome, buffer);
    }

    ordenar(matricula, num);

    for(i = 0; i < num; i++){
        printf("Matric.: %d Nome: %s Data Nasc.: %02d/%02d/%04d\n", matricula[i].numMatric, matricula[i].nome, matricula[i].diaNsc, matricula[i].mesNsc, matricula[i].anoNsc);
        free(matricula[i].nome);
    }

    free(matricula);
    return 0;
}