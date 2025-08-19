#define AZUL "\033[0;34m"
#define CINZA "\033[38;5;240m"
#define AMARELO "\033[38;5;214m"
#define ROXO "\033[0;35m"
#define RESET "\033[0m"

typedef struct{
    char nome[50];
    int numMatricula;
} aluno;

typedef struct descritor Lista;

Lista* cria_lista();
int tamanho_lista(Lista* li);
int insere_inicio(Lista* li, aluno* al, long long int N);
int insere_final(Lista* li, aluno* al, long long int N);
int consulta_posicao(Lista* li, aluno* al, long long int N); //pos = posição
void libera_lista(Lista* li);
void imprime_lista(Lista* li);