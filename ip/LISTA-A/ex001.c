#include <stdio.h>
 
int main(){ 
 
        float salarioMin, kwconsumo;
        
        scanf("%f", &salarioMin);
        scanf("%f", &kwconsumo);
        
        float kw = (0.7 * salarioMin) / 100;
        float kwgasto = kw * kwconsumo;
        float custoDesconto = kwgasto - kwgasto/10;
        
        printf("Custo por kW: R$ %.2f\n", kw);
        printf("Custo do consumo: R$ %.2f\n", kwgasto);
        printf("Custo com desconto: R$ %.2f\n", custoDesconto );
    
    return 0;
}