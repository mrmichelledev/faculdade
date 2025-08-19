#include <stdio.h>
 
int main(){
 
    int matricula, numDep;
    double salMin, salFun, txIm, imBru, imLiquid, result;

    scanf("%d", &matricula);
    scanf("%lf", &salMin);
    scanf("%d", &numDep);
    scanf("%lf", &salFun);
    scanf("%lf", &txIm);

    if (salFun > (salMin * 12)){
        imBru = salFun * 0.2;
    } else if (salFun > (salMin * 5)){
        imBru = salFun * 0.08;
    } else{
        imBru = 0;
    }

    imLiquid = imBru - (300 * numDep);

    result = imLiquid - (salFun * (txIm / 100));
    
    printf("MATRICULA = %d\n", matricula);
    printf("IMPOSTO BRUTO = %.2lf\n", imBru);
    printf("IMPOSTO LIQUIDO = %.2lf\n", imLiquid);
    printf("RESULTADO = %.2lf\n", result);

    if (result < 0){
        printf("IMPOSTO A RECEBER\n");
    } else if (result == 0){
        printf("IMPOSTO QUITADO\n");
    } else if (result > 0){
        printf("IMPOSTO A PAGAR\n");
    } 

    return 0;
}