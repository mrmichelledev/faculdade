#include <stdio.h>
 
int main(){
    
    double precoF, perDis, perImp, valorZ;
    
    scanf("%lf", &precoF);
    scanf("%lf", &perDis);
    scanf("%lf", &perImp);
    
    valorZ = precoF + ((perDis * precoF) / 100) + ((perImp * precoF)/ 100);
	
    printf("O VALOR DO CARRO E = %.2lf\n", valorZ);
    
    return 0;
}