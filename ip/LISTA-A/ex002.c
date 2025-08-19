#include <stdio.h>
 
int main(){
    
    double tempF, valPo;
    
    scanf("%lf", &tempF);
    scanf("%lf", &valPo);
    
    double convertFC = 5 * (tempF - 32) / 9;
    double quantChu = valPo * 25.4;
    
    printf("O VALOR EM CELSIUS = %.2lf\n", convertFC);
    printf("A QUANTIDADE DE CHUVA E = %.2lf\n", quantChu);
    
    return 0;
    
} 