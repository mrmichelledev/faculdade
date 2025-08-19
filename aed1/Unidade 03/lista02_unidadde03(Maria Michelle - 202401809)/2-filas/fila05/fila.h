#define MAX 100

typedef struct {
    char nome[30];
}chamada;

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int insere_Fila(Fila* fi, chamada nomeI);
int remove_Fila(Fila* fi, chamada *nomeI);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
int copia_Fila(Fila* f1, Fila* f2);
void imprime_Fila(Fila* f1, Fila* f2);

