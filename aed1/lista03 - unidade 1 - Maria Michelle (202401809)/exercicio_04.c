#include <stdio.h>
#include <math.h>

int reverse(int n, int num){
    if(n == 0) return num;

    return reverse(n / 10, num * 10 + (n % 10));
}

int main(){
    int n;
    
    do{
        scanf("%d", &n);
    } while(n < 0 || n > pow(10, 6));

    printf("%d", reverse(n, 0));

    return 0;
}