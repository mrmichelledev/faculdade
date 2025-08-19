#include <stdio.h>
 
int main() {
    
    int valorR, v100r, v50r, v10r, v1m, valorT;
    scanf("%d", &valorR);
    
    v100r = valorR / 100;
    valorT = valorR % 100;
    v50r = valorT / 50;
    valorT = valorR % 50;
    v10r = valorT / 10;
    valorT = valorR % 10;
    v1m = valorT / 1;
    
    printf("NOTAS DE 100 = %d\n", v100r);
    printf("NOTAS DE 50 = %d\n", v50r);
    printf("NOTAS DE 10 = %d\n", v10r);
    printf("MOEDAS DE 1 = %d\n", v1m);
    
    return 0;
}