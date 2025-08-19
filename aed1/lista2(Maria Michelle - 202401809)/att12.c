#include <stdio.h>

int main() {
    int var, *ptr1, **ptr2, ***ptr3;

    ptr3 = &ptr2;
    ptr2 = &ptr1;
    ptr1 = &var;

    printf("Digite o valor de var: ");
    scanf("%d", &var);

    int d = 2 * (*ptr1);
    int t = 3 * (**ptr2);
    int q = 4 * (***ptr3);

    printf("Dobro: %d, Triplo: %d, Quádruplo: %d\n", d, t, q);

    return 0;
}
