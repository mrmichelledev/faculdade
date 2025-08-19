#include <stdio.h>

int main(){
    int num1, num2, i;

    scanf("%d %d", &num1, &num2);

    if(num1%2 == 0){
        for(i = 0; i < num2; i++){
            num1 += 2;
            printf("%d ", num1 - 2);
        }
    } else {
        printf("O PRIMEIRO NUMERO NAO E PAR");
    }

    return 0;
}