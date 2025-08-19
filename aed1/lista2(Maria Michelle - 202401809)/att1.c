#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    char logg[50];
    int num;
    char bairro[50];
    char complemento[200];
    int cep;
    char cidade[50];
    char estado[50];
} loc;

typedef struct{
    char nome[100];
    int idade;
    loc endereco;
} info;

int main(){
    info dados;

    printf("Nome Completo: ");
    fgets(dados.nome, 100, stdin);
    printf("Idade: ");
    scanf("%d", &dados.idade);
    getchar();

    if(idade < 0 || idade > 120){
        printf("Idade invalida!");
        return 0;
    }
    
    printf("Endereco: \n");
    printf("\t.1 logradouro ");
    fgets(dados.endereco.logg, 50, stdin);
    printf("\t.2 numero ");
    scanf("%d", &dados.endereco.num);
    getchar();
    printf("\t.3 bairro ");
    fgets(dados.endereco.bairro, 50, stdin);
    printf("\t.4 complemento ");
    fgets(dados.endereco.complemento, 200, stdin);
    printf("\t.5 CEP ");
    scanf("%d", &dados.endereco.cep);
    getchar();
    printf("\t.6 cidade ");
    fgets(dados.endereco.cidade, 50, stdin);
    printf("\t.7 estado ");
    fgets(dados.endereco.estado, 50, stdin);
   
    printf("............................................................\n");
    printf("%s %d anos\n", dados.nome, dados.idade);
    printf("\n");
    printf("%d %s %s %s\n",
           dados.endereco.cep, dados.endereco.bairro, dados.endereco.cidade, dados.endereco.estado);
    printf("%d %s %s\n",
           dados.endereco.num, dados.endereco.logg, dados.endereco.complemento);
    printf("............................................................");

    return 0;
}
