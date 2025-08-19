#include <stdio.h>
#include <math.h>
 
int main() {
    
    double a, b, c, d, e, f, valX, valY;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    scanf("%lf", &d);
    scanf("%lf", &e);
    scanf("%lf", &f);
    
    valX = ((c*e) - (b*f)) / ((a*e) - (b*d));
    valY = ((a*f) - (c*d)) / ((a*e) - (b*d));
  
    printf("O VALOR DE X E = %.2lf\n", valX);
    printf("O VALOR DE Y E = %.2lf\n", valY);
    
    return 0;
}