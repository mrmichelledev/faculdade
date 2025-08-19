#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int potencia(int m, int pot, int n){
    if (n == 0)
        return 1;
    else if(n == 1)
        return m;
    else     
        return potencia(m * pot, pot, n - 1);
}

int main() {
    int i, j, num, m, n;
    scanf("%d", &num);
    
    for(i = 0; i < num; i++){
        scanf("%d %d", &m, &n);
        
        printf("%d\n", potencia(m, m, n));
    }

    return 0;
}