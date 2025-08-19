#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int num, i; char buffer[10000];
    scanf("%d", &num);
    getchar();

    char **nomes = (char**)malloc(num*sizeof(char*));

    for(i = 0; i < num; i++){
        fgets(buffer, 10000, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        nomes[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(nomes[i], buffer);
    }

    for(i = 0; i < num; i++){
        printf("%s\n", nomes[i]);
        free(nomes[i]);
    }

    free(nomes);
    return 0;
}