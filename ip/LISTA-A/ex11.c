#include <stdio.h>
 
int main() {
    
    int num, n1, n2, n3;
    scanf("%d", &num);
    
    n1 = num/100;
    n2 = (num%100)/10;
    n3 = num%10;
    
    printf("%d%d%d\n", n3, n2, n1);
    
    return 0;
}