#define MAX 100

typedef struct{
    int num;
} numero;

typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_ordenada(Lista* li, numero n);
int remove_primeiros(Lista* li, int remove);
int remove_ultimos(Lista* li, int remove);
int tamanho_lista(Lista* li);
void imprime_lista(Lista* li);