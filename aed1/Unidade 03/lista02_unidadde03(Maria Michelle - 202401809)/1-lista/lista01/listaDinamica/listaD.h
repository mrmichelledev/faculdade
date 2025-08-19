typedef struct{
    int matricula;
    char nome[30];
    float n1,n2,n3;
}aluno;

typedef struct descritor Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_inicio(Lista* li, aluno al);
int insere_lista_final(Lista* li, aluno al);
int remove_primeiros(Lista* li, int remove);
int remove_ultimos(Lista* li, int remove);
int tamanho_lista(Lista* li);
void imprime_lista(Lista* li);