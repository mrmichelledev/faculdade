#include <stdio.h>

int main(){
    double numPessoas, catGeral, catPopular, catArquibancada, catCadeiras, valPopular, valGeral, valArquibanq, valCadeiras; 
    int i, j,numCasos;
    
    scanf("%d", &numCasos);
    double rendaT[numCasos];
    for(i = 0; i < numCasos; i++){
        scanf("%lf %lf %lf %lf %lf", &numPessoas, &catPopular, &catGeral, &catArquibancada, &catCadeiras);
        
        valPopular = numPessoas * (catPopular / 100) * 1;
        valGeral = numPessoas * (catGeral / 100) * 5;
        valArquibanq = numPessoas * (catArquibancada / 100) * 10;
        valCadeiras = numPessoas * (catCadeiras / 100) * 20;

        rendaT[i] = valPopular + valGeral + valArquibanq + valCadeiras;
    }

    for(j = 0; j < numCasos; j++){

        printf("A RENDA DO JOGO N. %d E = %.2lf\n", j+1, rendaT[j]);
    }

    return 0;
}