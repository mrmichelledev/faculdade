#include <stdio.h>

int main(){
    double a[10], somatorio = 0;
    int i;
    
    printf("Digite 10 notas de 0 a 10: ");
    for(i = 0; i < 10; i++){
        scanf("%lf", &a[i]);

        if(a[i] >= 6){
            somatorio += a[i];
        }
    }

    printf("%.2lf", somatorio);
    return 0;
}