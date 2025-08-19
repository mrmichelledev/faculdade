#include <stdio.h>

int main() {
    
    int num, n1, n2, n3, newN;
    scanf("%d", &num);
    
    n1 = num/100;
    n2 = (num%100)/10;
    n3 = num%10;
    newN = (n1 + (n2 * 3) + (n3 * 5)) % 7;
    
    
    printf("O NOVO NUMERO E = %d%d%d%d\n", n1, n2, n3, newN);
    
    return 0;
}