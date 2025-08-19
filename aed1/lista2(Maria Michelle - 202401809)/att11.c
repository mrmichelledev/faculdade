#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    printf("Valores originais do array: ");
    printf("%d %d %d %d %d\n", *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3), *(ptr + 4));

    *(ptr) += 5;
    *(ptr + 1) += 5;
    *(ptr + 2) += 5;
    *(ptr + 3) += 5;
    *(ptr + 4) += 5;

    printf("Valores modificados do array: ");
    printf("%d %d %d %d %d\n", *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3), *(ptr + 4));

    return 0;
}
