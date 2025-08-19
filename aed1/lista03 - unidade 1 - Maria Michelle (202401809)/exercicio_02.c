#include <stdio.h>

int fib(int n) {
    int soma;
  
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
  
  
  soma = fib(n-1) + fib(n-2);
  return soma;
}

int main() {
    int n,i;
  
    do{
        scanf("%d", &n);
    }while (n < 0 || n > 1000);
  

    for (i = 0; i <= n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");

    return 0;
}