#include <time.h>  //clock(), CLOCKS_PER_SEC e clock_t
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
    long long int N[7] = {100, 500, 1000, 5000, 10000, 50000, 100000};
    aluno *aTeste, aConsulta;
    int i, j, pos;
    clock_t inicio, fim, inicioT, fimT;
    unsigned long int temp;
    

    Lista* li = cria_lista();
    FILE* file = fopen("tempo2.txt", "w");

    if (file == NULL){ 
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(file, "                  >>> RELATÓRIO DE DESEMPENHO <<<\n");
    fprintf(file, "Testes Realizados Com Valores De N = {100, 500, 1.000, 5.000, 10.000}\n");
    fprintf(file, "---------------------------------------------------------------------\n\n");

    aTeste = (aluno*)malloc(3 * sizeof(aluno));

    strcpy(aTeste[0].nome, "Maria Michelle");
    aTeste[0].numMatricula = 202401809;

    strcpy(aTeste[1].nome, "Eduarda");
    aTeste[1].numMatricula = 202401823;

    strcpy(aTeste[2].nome, "Thiago Rodrigo");
    aTeste[2].numMatricula = 202401956;

    insere_inicio(li, aTeste, 3);
    //imprime_lista(li);

    inicioT = clock();

    for(j = 0; j < 7; j++){
        printf("\nInserindo" CINZA" %d elementos" RESET" no" ROXO" inicio" RESET" da lista\n", N[j]);  

        //alocando dinamicamente
        aTeste = (aluno*)malloc(N[j] * sizeof(aluno));  

        inicio = clock();
        
        for(i = 0; i < N[j]; i++){
            strcpy(aTeste[i].nome, "Nome Aleatorio");
            aTeste[i].numMatricula = 123456789;
        }
        
        insere_inicio(li, aTeste, N[j]);
        
        fim = clock();
        temp = (fim - inicio) * 1000 / CLOCKS_PER_SEC;
        
        //imprime_lista(li);

        fprintf(file, "Tempo para inserir %d elementos no inicio da lista: %lu milissegundo\n", N[j], temp);

        //.................................................................

        printf("Inserindo" CINZA" %d elementos" RESET" no" ROXO" final" RESET" da lista\n", N[j]);

        inicio = clock();

        for(i = 0; i < N[j]; i++){
            strcpy(aTeste[i].nome, "Nome Aleatorio");
            aTeste[i].numMatricula = 123456789;
        }
            
        insere_final(li, aTeste, N[j]);

        fim = clock();
        temp = (fim - inicio) * 1000 / CLOCKS_PER_SEC;

        //imprime_lista(li);

        fprintf(file, "Tempo para inserir %d elementos no final da lista: %lu milissegundo\n", N[j], temp);

        //.................................................................

        printf("\nConsultando" AZUL" %d elementos aleatorios" RESET" na lista\n", N[j]);

        inicio = clock();

        srand(time(NULL));
        long long int tamanhoL= tamanho_lista(li);

        for (i = 0; i < N[j]; i++) {
            pos = rand() % tamanhoL + 1;

            consulta_posicao(li, &aConsulta, pos);
        }

        fim = clock();
        temp = (fim - inicio) * 1000 / CLOCKS_PER_SEC;
        fprintf(file, "Tempo para consultar %d elementos da lista: %lu milissegundo\n\n", N[j], temp);

        // Libera a memória alocada
        free(aTeste);  

        printf("\n................................................\n");
    }

    fimT = clock();
    temp = (fimT - inicioT) * 1000 / CLOCKS_PER_SEC;

    fprintf(file, "-----------------------------------\n\n");
    fprintf(file, "Tempo total para a execução dos testes: %lu milissegundo\n\n", temp);

    fclose(file);
    libera_lista(li);
    return 0;
}