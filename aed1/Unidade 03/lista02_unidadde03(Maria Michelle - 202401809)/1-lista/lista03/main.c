#include <stdio.h>
#include <stdlib.h>
#include "estoque.h" 

int main(){
    int select, cod;
    produto Produto, menorP;
    Lista* li = cria_lista();

    do{
        printf("\n====================================\n");
        printf("||        MENU DE GERENCIAMENTO      ||\n");
        printf("||-----------------------------------||\n");
        printf("||  1. Cadastrar   |  3. Menor preco ||\n");
        printf("||  2. Remover     |  4. Listar      ||\n");
        printf("||-----------------------------------||\n");
        printf("||              5. Sair              ||\n");
        printf("======================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &select);

        switch(select){
            case 1:
                printf("Digite o codigo do produto: ");
                scanf("%d", &Produto.codigo);
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]", Produto.nome);
                printf("Digite o preco do produto: ");
                scanf("%f", &Produto.preco);
                printf("Digite a quantidade em estoque: ");
                scanf("%d", &Produto.quant);
                if (cadastra_produto(li, Produto))
                    printf("Cadastrado com sucesso!\n");
                else
                    printf("Nao foi possivel cadastrar o produto\n");
                
                break;

            case 2:
                printf("Remover produto (codigo): ");
                scanf("%d", &cod);

                if (remove_produto(li, cod))
                    printf("Produto removido!\n");
                else 
                    printf("ERRO\n");
                
                break;

            case 3: {
                if(busca_produto_menor_preco(li, &menorP)){
                    printf("\nProduto com menor preco:\n");
                    printf("Codigo: %d\n", menorP.codigo);
                    printf("Nome: %s\n", menorP.nome);
                    printf("Preco: %.2f\n", menorP.preco);
                    printf("Quantidade disponivel em estoque: %d\n", menorP.quant);

                } else {
                    printf("Nenhum produto cadastrado.\n");
                }

                break;
            }
            case 4:
                imprime_lista(li);
                break;

            case 5:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }

    } while (select != 5);

    libera_lista(li);
    return 0;
}