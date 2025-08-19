#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file;
    file fopen("texto.txt", "r");

    if(file == NULL){
        printf("Arquivo nao encontrado!\n");
        exit(1);
    }

    
    return 0;
}