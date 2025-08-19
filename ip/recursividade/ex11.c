#include <stdio.h>
#include <stdlib.h>

int produto(int num1, int num2){
    if(num1 == 0 || num2 == 0)
        return 0;
    else if(num2 > 0)
        return num1 + produto(num1, num2 - 1);
}

int main() {
    int i, m, n, num;
    scanf("%d\n", &num);
    
    for(i = 0; i < num; i++){
        scanf("%d %d", &m, &n);
        
        printf("%d\n", produto(m, n));
    }

    return 0;
}