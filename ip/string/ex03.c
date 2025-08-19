#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int letras(char *txt){
    int i, j, quantLetras = 0, tamanhoStr = strlen(txt);
    char letraa[] = "qwrtypsdfhjklzxcvbnmQWRTYPSDFGHJKLZXCVBNMaeiouAEIOU";
    int tamanhoLetra = strlen(letraa);

    for(i = 0; i < tamanhoStr; i++){
        for(j = 0; j < tamanhoLetra; j++){
            if(txt[i] == letraa[j]){
                quantLetras++;
            }   
        }
    }

    return quantLetras;
}

int vogais(char *txt){
    int i, j, quantVogais = 0, tamanhoStr = strlen(txt);;
    char vog[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for(i = 0; i < tamanhoStr; i++){
        for(j = 0; j < 10; j++){
            if(txt[i] == vog[j]){
                quantVogais++;
            }
        }
    }

    return quantVogais;
}

int consoantes(char *txt){
    int i, j, quantConsoantes = 0, tamanhoStrr = strlen(txt);;
    char cons[] = "qwrtypsdfhjklzxcvbnmQWRTYPSDFGHJKLZXCVBNM";
    int tamanhoCons = strlen(cons);

    for(i = 0; i < tamanhoStrr; i++){
        for(j = 0; j < tamanhoCons; j++){
            if(txt[i] == cons[j]){
                quantConsoantes++;
            }
        }
    }

    return quantConsoantes;
}

int main(){
    int n, i;
    
    scanf("%d\n", &n);

    for(i = 0; i < n; i++){
        char txt[10000];
        fgets(txt, sizeof(txt), stdin);
        
        printf("Letras = %d\n", letras(txt));
        printf("Vogais = %d\n", vogais(txt));
        printf("Consoantes = %d\n", consoantes(txt));
    }
    

    return 0;
}