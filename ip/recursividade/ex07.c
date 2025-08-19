#include <stdio.h>
#include <stdlib.h>

int piso(int logg){
    if (logg < 1)
        return 0;
    
    return 1 + piso((int)logg/2);
}

int main(){
    int i, teste, logg;
    scanf("%d", &teste);

    for(i =0; i < teste; i++){
        scanf("%d", &logg);
        printf("%d\n", piso(logg) - 1);
    }

    return 0;
}