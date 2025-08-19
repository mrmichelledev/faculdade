#include <stdio.h>
#include <stdlib.h>

int soma(int num){
    if(num < 1) 
        return 0;

    return num + soma(num - 1);
}

int main(){
    int num, i, t;
    scanf("%d", &t);

    for(i =0; i < t; i++){
        scanf("%d", &num);
        printf("%d\n", soma(num));
    }

    return 0;
}