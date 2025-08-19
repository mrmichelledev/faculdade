#include <stdio.h>
#include <string.h>

void semzero(char *soma){
    char somaN[20];
    int j = 0, i;
    for (i = 0; soma[i] != '\0'; i++) {
        if (soma[i] != '0') {
            somaN[j++] = soma[i];
        }
    }
    somaN[j] = '\0';
    strcpy(soma, somaN);
}

int main(){
    int m, n, sm;
    char soma[20];

    while(1){
        sm = 0;
        scanf("%d %d", &m, &n);

        if(m == 0 || n == 0) break;

        sm = m + n;
        
        sprintf(soma, "%d", sm);
        
        semzero(soma);

        printf("%s\n", soma);

    }

    return 0;
}
