#include <stdio.h>

int main()
{
  int n, i, fatorial;

  scanf("%d", &n);

  fatorial = 1;
  
  for(i = 1; i <= n; i++;) {
    fatorial = fatorial * i;
  }

  printf("%d! = %d\n", n, fatorial);

  return 0;
}