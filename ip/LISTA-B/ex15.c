#include <stdio.h>

int inNum(int num) {
    int numIn = 0;
    
    while (num != 0) {
        numIn = numIn * 10 + num % 10;
        num /= 10;
    }
    
    return numIn;
}

int main() {
    int num, contador = 0;
    scanf("%d", &num);
    int num2 = num;

    int numIn = inNum(num);
    
     while(num != 0){
        num /= 10;
        contador++;
    }
    
    if(contador > 5){
        printf("NUMERO INVALIDO\n");
    } else if(num2 == numIn){
        printf("PALINDROMO\n");
    } else{
        printf("NAO PALINDROMO\n");
    }
    
    return 0;
}