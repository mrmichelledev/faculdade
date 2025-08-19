#include <stdio.h>
#include <stdlib.h>

int soma(int coelho){
    if (coelho < 1)
        return 0;
    
    if(coelho%2 == 0) 
        return 3 + soma(coelho - 1);
    else
        return 2 + soma(coelho - 1);
}

int main(){
    int coelho, i, teste, result, quant;
    scanf("%d", &teste);

    for(i =0; i < teste; i++){
        result = 0;
        quant = 0;
        scanf("%d", &coelho);
        printf("%d\n", soma(coelho));
    }

    return 0;
}