#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mercadoria{
    char nome[50];
    double preco;
    int qtdProduto;
};

int main(){
    int idas, estoque, carrinho, i, j, k;
    double recibo;
    struct mercadoria produtos[50], lista[50];
    scanf("%d", &idas);

    for(i = 0; i < idas; i++){
        recibo = 0;
        scanf("%d", &estoque);
        for(j = 0; j < estoque; j++){
            scanf("%s %lf", produtos[j].nome, &produtos[j].preco);
        }
        scanf("%d", &carrinho);
        for(j = 0; j < carrinho; j++){
            scanf("%s %d", lista[j].nome, &lista[j].qtdProduto);
        }
        
        for(j = 0; j < carrinho; j++){
            for(k = 0; k < estoque; k++){
                if(strcmp(lista[j].nome, produtos[k].nome) == 0)
                    recibo += (produtos[k].preco * lista[j].qtdProduto);
            }
        }
        
        printf("R$ %.2lf\n", recibo);
    }
}