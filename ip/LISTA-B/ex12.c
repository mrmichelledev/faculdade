#include <stdio.h>
 
int main(){
 
    int num, dia,mes, ano, digitos;
    char meses[12][20] = {"janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    
    scanf("%d", &num);
    
    dia = num/1000000;
    mes = ((num/10000)%100) - 1;
    ano = num%10000;
    digitos = num/100000000;
    
    if ((mes == 1 && dia > 28) || dia > 31 || mes > 11 || (mes == 0 || mes == 2 || mes == 4 || mes == 7 || mes == 9) && dia > 30 || digitos == 0) {
        printf("Data invalida!\n");
    } else if (mes >= 0 && mes <= 11){
        printf("%d de %s de %d", dia, meses[mes], ano);
    }

    return 0;
}