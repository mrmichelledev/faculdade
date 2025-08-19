#include <stdio.h>
#include <math.h>

int main() {
    
    int valH, valM, valS, tempo;
    
    scanf("%d", &valH);
    scanf("%d", &valM);
    scanf("%d", &valS);
    
    tempo = valH * 3600 + valM * 60 + valS;
    
    printf("O TEMPO EM SEGUNDOS E = %d\n", tempo);
    
    return 0;
}