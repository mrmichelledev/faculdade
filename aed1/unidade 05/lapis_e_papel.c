#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSort(int *vetor, int tamanho, int *comparacao, int *trocas){
    int i, j;

    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - i - 1; j++){
            (*comparacao)++;
            if(vetor[j] > vetor[j + 1]){
                swap(&vetor[j], &vetor[j + 1]);
                (*trocas)++;
            } 
        }
    }

    // A = Foram feitas 15 comparacoes e 15 trocas com bubble sort! {1 5 9 17 19 21}
    // B = Foram feitas 66 comparacoes e 36 trocas com bubble sort! {1 2 3 4 5 6 7 8 9 10 11 12} 
    // C = Foram feitas 45 comparacoes e 32 trocas com bubble sort! {6 8 14 17 18 21 23 23 29 29} 
}

void insertionSort(int *vetor, int tamanho, int *comparacao, int *trocas){
    int i, j;

    for (i = 1; i < tamanho; i++) { 
		
		j = i;

        (*comparacao)++;
		while (j > 0 && vetor[j] < vetor[j-1]) {
			swap(&vetor[j], &vetor[j - 1]);
            (*trocas)++;
			j -= 1;
		}
	
	}	

    // A = Foram feitas 5 comparacoes e 15 trocas com insertion sort! {1 5 9 17 19 21}
    // B = Foram feitas 11 comparacoes e 36 trocas com insertion sort! {1 2 3 4 5 6 7 8 9 10 11 12} 
    // C = Foram feitas 9 comparacoes e 32 trocas com insertion sort! {6 8 14 17 18 21 23 23 29 29}
}

void merge(int *vetor, int primeiro, int meio, int ultimo, int *comparacao, int *trocas){
    int i, j, k;

    int n1 = meio - primeiro + 1;
    int n2 = ultimo - meio;

    int esquerda[n1], direita[n2];

    for(i = 0; i < n1; i++)
        esquerda[i] = vetor[primeiro + i];

    for(j = 0; j < n2; j++)
        direita[j] = vetor[meio + 1 + j];

    i = 0, j = 0, k = primeiro;

    while(i < n1 && j < n2){
        (*comparacao)++;

        if(esquerda[i] <= direita[j]){
            vetor[k] = esquerda[i];
            (*trocas)++;
            i++;
        } else {
            vetor[k] = direita[j];
            (*trocas)++;
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esquerda[i];
        (*trocas)++;
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = direita[j];
        (*trocas)++;
        j++;
        k++;
    }
}

void mergeSort(int *vetor, int inicio, int fim, int *comparacao, int *trocas){
    (*comparacao)++;
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vetor, inicio, meio, comparacao, trocas);
        mergeSort(vetor, meio + 1, fim, comparacao, trocas);

        merge(vetor, inicio, meio, fim, comparacao, trocas);
    }	

    // A = Foram feitas 18 comparacoes e 16 trocas com merge sort! {1 5 9 17 19 21}
    // B = Foram feitas 50 comparacoes e 44 trocas com merge sort! {1 2 3 4 5 6 7 8 9 10 11 12} 
    // C = Foram feitas 40 comparacoes e 34 trocas com merge sort! {6 8 14 17 18 21 23 23 29 29}
}

int partition(int *vetor, int inicio, int fim, int *comparacao, int *trocas){
    int j;
    int i = (inicio - 1);
    int pivo = vetor[fim];

    for(j = inicio; j < fim; j++){
        (*comparacao)++;
        if(vetor[j] <= pivo){
            i++;
            swap(&vetor[i], &vetor[j]);
            (*trocas)++;
        }
    }

    swap(&vetor[i + 1], &vetor[fim]);
    (*trocas)++;

    return (i + 1);
}

void quickSort(int *vetor, int inicio, int fim, int *comparacao, int *trocas){
    (*comparacao)++;
    if(inicio < fim){
        int pivo = partition(vetor, inicio, fim, comparacao, trocas);

        quickSort(vetor, inicio, pivo - 1, comparacao, trocas);
        quickSort(vetor, pivo + 1, fim, comparacao, trocas);
    }

    // A = Foram feitas 26 comparacoes e 11 trocas com quick sort! {1 5 9 17 19 21}
    // B = Foram feitas 62 comparacoes e 14 trocas com quick sort! {1 2 3 4 5 6 7 8 9 10 11 12} 
    // C = Foram feitas 38 comparacoes e 14 trocas com quick sort! {6 8 14 17 18 21 23 23 29 29}
}

int main(){
    int A[6] = {21, 19, 17, 9, 5, 1};
    int B[12] = {2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1};
    int C[10] = {18, 29, 17, 29, 23, 21, 23, 8, 14, 6};
    int i, comparacao = 0, trocas = 0;

    quickSort(C, 0, 10 - 1, &comparacao, &trocas);

    printf("Foram feitas %d comparacoes e %d trocas com quick sort!\n", comparacao, trocas);

    for(i = 0; i < 10; i++)
        printf("%d ", C[i]);

    return 0;
}