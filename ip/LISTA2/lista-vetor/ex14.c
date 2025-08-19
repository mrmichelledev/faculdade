#include <stdio.h>

int main(){
    int amostra[1000000], n, i, j, aux, soma = 0;
    double mediana;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
       scanf("%d", &amostra[i]);
    }
    
    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            if(amostra[i] > amostra[j]){
                aux = amostra[i];
                amostra[i] = amostra[j];
                amostra[j] = aux;
            }
        }
    }
    
    if(n%2 == 0){
      mediana =  (amostra[(int)(n/2)] + amostra[(int)(n/2) + 1]);
      printf("%.2lf\n", mediana/2);
    } else if(n%2 != 0){
      mediana = amostra[(int)(n - 1) / 2];
      printf("%.2lf\n", mediana);
    }
    
    return 0;
}