typedef struct{
    int matricula;
    char nome[30];
} aluno;

typedef struct elemento* Lista;
//al = aluno

Lista* cria_lista();
void libera_lista(Lista* al);
int tamanho_lista(Lista* al);
int lista_cheia(Lista* al);
int lista_vazia(Lista* al);
int insere_aluno(Lista* al, aluno aluno);
int consulta_aluno(Lista* al, int matricula, aluno *aluno);
int atualiza_aluno(Lista* al, int matricula, aluno atualizado);
int exclui_aluno(Lista* al, aluno aluno);
void imprime_aluno(Lista* al);