#include<stdio.h>
#include<stdlib.h>

main(){
FILE *fp;
fp = fopen("num.txt", "r");

if(fp == NULL){
    printf("erro.");
    return 0;
}

int a, b, c;

fscanf(fp, "%d %d %d", &a, &b, &c);
printf("%d %d %d", a, b, c);
  
fclose(fp);

system("pause");
return 0;
}