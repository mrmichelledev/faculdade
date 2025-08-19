#include <stdio.h>
#include <string.h>

void combinaP(char *palavra1, char *palavra2, char *combinador){
    int tamP1 = strlen(palavra1);
    int tamP2 = strlen(palavra2);
    int i = 0, j = 0, k = 0;
    
    while(i < tamP1 && j < tamP2){
        combinador[k++] = palavra1[i++];
        combinador[k++] = palavra2[j++];
    }
    
    while(i < tamP1){
        combinador[k++] = palavra1[i++];
    }
    
    while(j < tamP2){
        combinador[k++] = palavra2[j++];
    }
    
    combinador[k] = '\0';
}

int main() {
    int n, i;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
      char palavra1[51], palavra2[51], combinador[101]; 
      scanf("%s %s", palavra1, palavra2);
      
      combinaP(palavra1, palavra2, combinador);
      
      printf("%s\n", combinador);
    }
    
    return 0;
}
