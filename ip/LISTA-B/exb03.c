#include <stdio.h>
#include<math.h>

int main()
{
    int num, div3, div5;
    scanf("%d", &num);
    
    div3 = num%3;
    div5 = num%5;
    
    if (div3 == 0 && div5 == 0) {
        printf("O NUMERO E DIVISIVEL\n");
    } else {
        printf("O NUMERO NAO E DIVISIVEL\n");
    }
    
    return 0;
}