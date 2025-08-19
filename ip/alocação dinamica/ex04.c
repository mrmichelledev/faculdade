#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double u;
    double x;
    double y;
    double z;
} vetor;

double calcula(double vu, double vx, double vy, double vz){
    return sqrt(pow(vu, 2) + pow(vx, 2) + pow(vy, 2) + pow(vz, 2));
}

void ordenar(double *a, double *b){
    double aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void oCrescente(double *norma, int tam, vetor *vetores){
    int i, j;
    for (i = 0; i < tam - 1; i++) {
        for (j = 0; j < tam - i - 1; j++) {
            if (norma[j] > norma[j + 1]) {
                ordenar(&norma[j], &norma[j + 1]);
                ordenar(&vetores[j].u, &vetores[j + 1].u);
                ordenar(&vetores[j].x, &vetores[j + 1].x);
                ordenar(&vetores[j].y, &vetores[j + 1].y);
                ordenar(&vetores[j].z, &vetores[j + 1].z);
            }
        }
    }
}

int main(){
    int num, i;
    double *norma;
    scanf("%d", &num);

    vetor *vetores = (vetor*) malloc(num * sizeof(vetor));
    norma = (double*) malloc(num * sizeof(double));

    for(i= 0; i < num; i++){
        scanf("%lf %lf %lf %lf", &vetores[i].u, &vetores[i].x, &vetores[i].y, &vetores[i].z);
        norma[i] = calcula(vetores[i].u, vetores[i].x, vetores[i].y, vetores[i].z);
    }

    oCrescente(norma, num, vetores);

    for(i= 0; i < num; i++){
        printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", vetores[i].u, vetores[i].x, vetores[i].y, vetores[i].z, norma[i]);
    }
    
    free(norma);
    free(vetores);
    return 0;
}
