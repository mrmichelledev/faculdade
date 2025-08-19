#include <stdio.h>

int main() {
    
    int n1, n2, n3, soma, i;
    scanf("%d %d %d", &n1, &n2, &n3);

    for(i = 0; i < n3; i++){
        soma += n1 + (i *n2);
    }
    
    printf("%d", soma);

    return 0;
}