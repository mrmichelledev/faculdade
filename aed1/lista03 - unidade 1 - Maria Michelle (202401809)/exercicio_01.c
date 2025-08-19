#include <stdio.h>
#include <stdlib.h>

int numNaturais(int n, int nat){
    if(n < 1)
        return 0;
    
    printf("%d ", 1 + nat);
    return numNaturais(n - 1, nat + 1);
}

int main(){
    int n, i;

    do{
        scanf("%d", &n);
    }while (n < 1 || n > 5000);
    
    numNaturais(n, 0);

    return 0;
}