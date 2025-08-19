#include <stdio.h>
#include <math.h>

int main() {
    
    double l1, l2, l3, tt, areaT;
    
    scanf("%lf", &l1);
    scanf("%lf", &l2);
    scanf("%lf", &l3);
    
    tt = (l1 + l2 + l3) / 2;
    areaT = sqrt(tt*(tt - l1)*(tt - l2)*(tt - l3));
    
    printf("A AREA DO TRIANGULO E = %.2lf\n", areaT);
    
    return 0;
}