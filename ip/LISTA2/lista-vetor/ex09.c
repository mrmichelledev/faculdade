#include <stdio.h>
#include<math.h>

int main(){
    int numP, i;
    double x[1000], y[1000], z[1000], dis[1000];
    
    scanf("%d", &numP);
    
    for(i = 0; i < numP; i++){
        scanf("%lf %lf %lf", &x[i], &y[i], &z[i]);
    }
    
    
    for(i = 0; i < numP - 1; i++){
        dis[i] = sqrt(pow((x[i] - x[i+1]), 2) + pow((y[i] - y[i+1]), 2) + pow((z[i] - z[i+1]), 2));
    }
    
    for(i = 0; i < numP - 1; i++){
        printf("%.2lf\n", dis[i]);
    }
    
    return 0;
}