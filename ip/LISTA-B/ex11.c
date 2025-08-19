#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, delta, x1, x2, aux;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    
    delta = pow(b, 2) - (4 * a * c);
    x2 = (-b + sqrt(delta)) / (2 * a);
    x1 = (-b - sqrt(delta)) / (2 * a);
    
    if (x1 > x2)
    {
        aux = x1;
        x1 = x2;
        x2 = aux;
    }
    
    if (delta == 0){
       printf("RAIZ UNICA\n");
       printf("X1 = %.2lf\n", x1);
    } else if (delta < 0){
       printf("RAIZES IMAGINARIAS\n");
    } else if (delta > 0){
       printf("RAIZES DISTINTAS\n");
       printf("X1 = %.2lf\n", x1);
       printf("X2 = %.2lf\n", x2);
    }
    
    return 0;
}
