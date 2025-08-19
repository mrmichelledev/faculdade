#include<stdio.h>
#include<string.h>

int quantLeds(char numeros){
    int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    
    return leds[numeros - '0'];
}

int ledsTotal(char *numeros){
    int tamanhoStr = strlen(numeros), somaStr = 0, i;
    
    for(i = 0; i < tamanhoStr; i++){
        somaStr += quantLeds(numeros[i]);
    }
    
    return somaStr;
}

int main(){
    int n, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        char numeros[1000];
        scanf("%s", numeros);
        
        printf("%d leds\n", ledsTotal(numeros));
    }
    

    return 0;
}
