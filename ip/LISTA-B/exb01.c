#include <stdio.h>

int main()
{
    double nota1, nota2, nota3, result;
    scanf("%lf", &nota1);
    scanf("%lf", &nota2);
    scanf("%lf", &nota3);
    
    result = (nota1 + nota2 + nota3) / 3;
    
    if(result >= 6){
        printf("MEDIA = %.2lf\n", result);
        printf("APROVADO\n");
    } else {
        printf("MEDIA = %.2lf\n", result);
        printf("REPROVADO\n");
    }
    
    return 0;
}