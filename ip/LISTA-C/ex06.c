#include <stdio.h>

int main()
{
    int num, i;
    double somatorio = 0;
    float k = 1;

    scanf("%d", &num);

    if (num <= 1){
        printf("Numero invalido!\n");
        return 1;
    } else {
        for (i = 1; i <= num; i++){
            somatorio += k / i;
        }

        printf("%.6lf\n", somatorio);
    }

    return 0;
}