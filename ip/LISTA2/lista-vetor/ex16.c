#include <stdio.h>

int main(){
    int  alunosPre, minAulas, tempChegada[1000], i, naoCancela = 0, presentes[1000];
    
    scanf("%d %d", &alunosPre, &minAulas);
    
    for(i = 0; i < alunosPre; i++){
        scanf("%d", &tempChegada[i]);
        if (tempChegada[i] <= 0){
            naoCancela++;
            presentes[naoCancela] = i;
        }
    }
    
    if(naoCancela < minAulas){
        printf("SIM"); // CANCELA A AULA
        
    } else {
        printf("NAO\n"); // NAO CANCELA A AULA
        
        for(i = naoCancela; i > 0; i--){
            printf("%d\n", presentes[i]+1);
        }
    }


    return 0;
}