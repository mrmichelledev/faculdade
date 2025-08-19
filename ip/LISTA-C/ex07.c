#include <stdio.h>

int main(){
    
    int matricula, i, freq;
    double prova[8], lista[5],  trabalho, somaP = 0, somaL = 0, notaFinal;

    scanf("%d", &matricula);

    for (i = 0; i < 8; i++){
        scanf("%lf", &prova[i]);
        somaP += prova[i];
    }

    for (i = 0; i < 5; i++){
        scanf("%lf", &lista[i]);
        somaL += lista[i];
    }

    scanf("%lf %d", &trabalho, &freq);

    notaFinal = 0.7 * (somaP / 8) + 0.15 * (somaL / 5) + 0.15 * trabalho;
    
    printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: ", matricula, notaFinal);
 
    if(notaFinal >= 6 && freq >= (0.75 * 128)){
        printf("APROVADO\n");
    } else if(freq > (0.75 * 128) && notaFinal < 6){
        printf("REPROVADO POR NOTA\n");
    } else if(freq < (0.75 * 128) && notaFinal >= 6){
        printf("REPROVADO POR FREQUENCIA INSUFICIENTE\n");
    } else if(freq < (0.75 * 128) && notaFinal < 6){
        printf("REPROVADO POR FREQUENCIA E POR NOTA\n");
    }
 
 return 0;   
}