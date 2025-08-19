#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char *nome;
    char *classe;
} Animal;

void swap(Animal *a, Animal *b){
    Animal aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSort(Animal *vetor, int tamanho){
    int i, j;

    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - i - 1; j++){
            if(strcmp(vetor[j].nome, vetor[j + 1].nome) > 0){
                swap(&vetor[j], &vetor[j + 1]);
            } 
        }
    }
}


int main(){
    int i;

    Animal zoologico[] = {{10001, "Leao", "Mamifero"},
                          {10002, "Aguia", "Ave"},
                          {10003, "Crocodilo", "Reptil"},
                          {10004, "Elefante", "Mamifero"},
                          {10005, "Pinguim", "Ave"},
                          {10006, "Tigre", "Mamifero"},
                          {10007, "Iguana", "Reptil"},
                          {10008, "Golfinho", "Mamifero"},
                          {10009, "Cavalo", "Mamifero"},
                          {10010, "Corvo", "Ave"}};

    printf("Lista nao ordenada:\n");
    for(i = 0; i < 10; i++)
        printf("%d - %s (%s)\n", zoologico[i].codigo, zoologico[i].nome, zoologico[i].classe);

    bubbleSort(zoologico, 10);

    printf("\nLista ordenada:\n");
    for(i = 0; i < 10; i++)
        printf("%d - %s (%s)\n", zoologico[i].codigo, zoologico[i].nome, zoologico[i].classe);

    return 0;
}