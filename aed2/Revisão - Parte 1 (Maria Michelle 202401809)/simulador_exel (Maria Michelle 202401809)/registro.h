#define MAX 30

typedef struct {
    char nome[30]; 
    float n1;
    float n2; 
    int frequencia;
    float media;
    char situacao[15];
} aluno;

typedef struct elemento* Lista;

int aprovados, reprovados;

Lista* cria_lista();
void libera_lista(Lista* li);
void insere_aluno(Lista* li, aluno al); 
void media_aluno(Lista* li);
float media_geral(Lista* li);
void situacao_aluno(Lista* li);
void imprime_lista(Lista* li);