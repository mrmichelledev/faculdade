#include <stdio.h>
#include <math.h>

int main() {
    
    double massaT, ace, tempS, vel, vel2, spac, trab;
    scanf("%lf", &massaT);
    scanf("%lf", &ace);
    scanf("%lf", &tempS);
    
    vel = ace * tempS * 3.6;
    vel2 = ace * tempS;
    spac = (ace * pow(tempS, 2)) / 2;
    trab = (massaT * 1000 * pow(vel2, 2)) / 2;
    
    printf("VELOCIDADE = %.2lf\n", vel);
    printf("ESPACO PERCORRIDO = %.2lf\n", spac);
    printf("TRABALHO REALIZADO = %.2lf\n", trab);
    
    return 0;
}