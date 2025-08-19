typedef struct{
    int codigo; //código do produto
    char nome[30]; //nome do produto
    float preco; //valor do produto
    int quant; //quantidade disponível em estoque
}produto;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int cadastra_produto(Lista* li, produto p);
int remove_produto(Lista* li, int codigo);
int busca_produto_menor_preco(Lista* li, produto *menorP);
void imprime_lista(Lista* li);
