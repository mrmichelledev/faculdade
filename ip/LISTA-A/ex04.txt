#include <stdio.h>
#include <math.h>

int main()
{
    
    double a, b, c;
    
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    
    double valorD = pow(b, 2) - 4 * a * c;
    
    printf("O VALOR DE DELTA E = %.2lf\n", valorD);

    return 0;
}