#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double u;
    double x;
    double y;
    double z;
} pontos;

void calcula(pontos *ponto, int tam){
    int i; double dis;

    for(i = 0; i < tam - 1; i++){
        dis = sqrt(pow(ponto[i].u - ponto[i + 1].u, 2) + 
                pow(ponto[i].x - ponto[i + 1].x, 2) + 
                pow(ponto[i].y - ponto[i + 1].y, 2) + 
                pow(ponto[i].z - ponto[i + 1].z, 2));

        printf("%.2f\n", dis);
        dis = 0;
    }
}

int main(){
    int num, i;
    scanf("%d", &num);
    pontos *ponto = (pontos*)malloc(num * sizeof(pontos));

    for(i = 0; i < num; i++)
        scanf("%lf %lf %lf %lf", &ponto[i].u, &ponto[i].x, &ponto[i].y, &ponto[i].z);

    calcula(ponto, num);

    free(ponto);
    return 0;
}