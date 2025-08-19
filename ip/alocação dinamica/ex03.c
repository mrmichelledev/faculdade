#include <stdio.h>
#include <string.h>

typedef struct{
    char nomeP[50];
    char sdc[50];
}nomes;

void tradutor(char pais[], nomes lista[], int tam){
    int i;
    for (i = 0; i < tam; i++) {
        if (strcmp(pais, lista[i].nomeP) == 0) {
            printf("%s\n", lista[i].sdc);
            return;
        }
    }
    printf("-- NOT FOUND --\n");
}

int main() {
    nomes lista[50] = {
        {"brasil", "Feliz Natal!"},
        {"alemanha", "Frohliche Weihnachten!"},
        {"austria", "Frohe Weihnacht!"},
        {"coreia", "Chuk Sung Tan!"},
        {"espanha", "Feliz Navidad!"},
        {"grecia", "Kala Christougena!"},
        {"estados-unidos", "Merry Christmas!"},
        {"inglaterra", "Merry Christmas!"},
        {"australia", "Merry Christmas!"},
        {"portugal", "Feliz Natal!"},
        {"suecia", "God Jul!"},
        {"turquia", "Mutlu Noeller"},
        {"argentina", "Feliz Navidad!"},
        {"chile", "Feliz Navidad!"},
        {"mexico", "Feliz Navidad!"},
        {"antardida", "Merry Christmas!"},
        {"canada", "Merry Christmas!"},
        {"irlanda", "Nollaig Shona Dhuit!"},
        {"belgica", "Zalig Kerstfeest!"},
        {"italia", "Buon Natale!"},
        {"libia", "Buon Natale!"},
        {"siria", "Milad Mubarak!"},
        {"marrocos", "Milad Mubarak!"},
        {"japao", "Merii Kurisumasu!"}
    };

    char nome[50];
    while (scanf("%s", nome) != EOF) {
        tradutor(nome, lista, 24);
    }

    return 0;
}
