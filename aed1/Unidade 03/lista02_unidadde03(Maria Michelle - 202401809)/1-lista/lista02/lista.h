#define VERDE "\x1B[92m"
#define RED "\033[1;31m"
#define RESET "\x1B[0m"
#define AZUL "\033[36m"

typedef struct{
    int matricula;
    char nome[30];
}aluno;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_ordenada(Lista* li, aluno al);
void retorna_ant_prox(Lista* li, aluno *al);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);