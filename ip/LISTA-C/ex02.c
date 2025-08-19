#include <stdio.h>

int main(){

    int numF, i, j;

    scanf("%d", &numF);
    
    double celsius[numF], tempFahrenheit[numF];

    for(i = 0; i < numF; i++){
        scanf("%lf", &tempFahrenheit[i]);
        celsius[i] = (5 * (tempFahrenheit[i] - 32)) / 9;
    }
    
    for(j = 0; j < numF; j++){
        printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS \n", tempFahrenheit[j], celsius[j]);
    }

    return 0;
}