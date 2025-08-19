#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numMatric;
    int diaNsc;
    int mesNsc;
    int anoNsc;
    char *nome;
} dados;

int comparaDataNasc(dados aluno1, dados aluno2) {
    if (aluno1.anoNsc != aluno2.anoNsc)
        return aluno1.anoNsc - aluno2.anoNsc;
    if (aluno1.mesNsc != aluno2.mesNsc)
        return aluno1.mesNsc - aluno2.mesNsc;
    return aluno1.diaNsc - aluno2.diaNsc;
}

void ordenar(dados *matricula, int tam) {
    int i, j;
    dados aux;
    
    for (i = 0; i < tam - 1; i++) {
        for (j = 0; j < tam - i - 1; j++) {
            if (comparaDataNasc(matricula[j], matricula[j + 1]) > 0) {
                aux = matricula[j];
                matricula[j] = matricula[j + 1];
                matricula[j + 1] = aux;
            }
        }
    }
}

int main() {
    int num, i, j;
    char buffer[200];
    
    if (scanf("%d", &num) != 1 || num <= 0) {
        fprintf(stderr, "Invalid number of students.\n");
        return 1;
    }
    getchar();

    dados *matricula = (dados*)malloc(num * sizeof(dados));
    if (matricula == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < num; i++) {
        if (scanf("%d %d %d %d", &matricula[i].numMatric, &matricula[i].diaNsc, &matricula[i].mesNsc, &matricula[i].anoNsc) != 4) {
            fprintf(stderr, "Invalid input for student data.\n");
            free(matricula);
            return 1;
        }
        getchar();

        fgets(buffer, 200, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        matricula[i].nome = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if (matricula[i].nome == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            for (j = 0; j < i; j++) {
                free(matricula[j].nome);
            }
            free(matricula);
            return 1;
        }
        strcpy(matricula[i].nome, buffer);
    }

    ordenar(matricula, num);

    for (i = 0; i < num; i++) {
        printf("Matric.: %d Nome: %s Data Nasc.: %02d/%02d/%04d\n",
               matricula[i].numMatric, matricula[i].nome,
               matricula[i].diaNsc, matricula[i].mesNsc, matricula[i].anoNsc);
        free(matricula[i].nome);
    }

    free(matricula);
    return 0;
}
