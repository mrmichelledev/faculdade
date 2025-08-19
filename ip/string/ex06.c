#include <stdio.h>
#include <string.h>

int verific(char *world){
    char world2[200];
    int i, tam = strlen(world);
    
    for(i = 0; i < tam; i++){
        world2[i] = world[tam - i - 1];
    }
    
    return strcmp(world, world2);
}

int main(){
    char world[200];

    while(scanf("%s", world) != EOF){
        if(verific(world) == 0){
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }
    
    printf("\n");
    
    return 0;
}