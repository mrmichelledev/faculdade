#include <stdio.h>
#include <math.h>
 
int main() {
    
    double altP, arestH, areaH, volP;
    
    scanf("%lf", &altP);
    scanf("%lf", &arestH);
    
    areaH = (3 * pow(arestH, 2) * sqrt(3)) / 2;
    volP = (areaH * altP)/3;
    
    printf("O VOLUME DA PIRAMIDE E = %.2lf METROS CUBICOS\n", volP);
    
    return 0;
}

