#include <stdio.h>

int notas(int valor, int cedulas[], int quantN[], int tipoNota) {
    int i;

    if (valor < 0 || tipoNota == 6) {
        return 0;
    }

    int totalM = 0;
    for (i = 0; i <= quantN[tipoNota]; i++) {
        if (valor - i * cedulas[tipoNota] == 0) {
            totalM++;
        } else {
            totalM += notas(valor - i * cedulas[tipoNota], cedulas, quantN, tipoNota + 1);
        }
    }

    return totalM;
}

int main(){
    int s, i, cont, quantN[6];
    int cedulas[6] = {2, 5, 10, 20, 50, 100};
    
    do{
        scanf("%d", &s);
    }while (s < 2 || s > 5000);
    
    for (i = 0; i < 6; i++) {
        scanf("%d", &quantN[i]);
    }

    cont = notas(s, cedulas, quantN, 0);

    printf("%d\n", cont);

    return 0;
}