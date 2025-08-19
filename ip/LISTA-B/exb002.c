#include <stdio.h>

#define RES 'R'
#define COM 'C'
#define IND 'I'

int main(void){
    unsigned contaCliente;
    double consumeAgua, valorConsumo;
    char tipoConsumidor;
    
    scanf("%u", &contaCliente);
    scanf("%lf", &consumeAgua);
    scanf("%c", &tipoConsumidor);
    
    printf("CONTA = %u\n", contaCliente);
    
    if (tipoConsumidor == RES){
        
    valorConsumo = 5 + (consumeAgua * 0.05);
    printf("VALOR DA CONTA = %.2lf\n", valorConsumo);
        
    } else if (tipoConsumidor == COM){
        
    valorConsumo = 500 + (consumeAgua - 80) * 0.25;
    printf("VALOR DA CONTA = %.2lf\n", valorConsumo);
          
    } else if (tipoConsumidor == IND){
        
    valorConsumo = 800 + (consumeAgua - 100) * 0.04;
    printf("VALOR DA CONTA = %.2lf\n", valorConsumo);
          
    }
    
    return 0;
}