#define TAM 3000
#define TAM_VETOR 1000

#define CINZA "\033[38;5;250m"
#define RESET "\033[0m"

int i;

typedef struct dados {
    int cod;
    char nome[100];
} Dados;

typedef struct no {
    Dados dado;
    struct no* prox;
} No;

typedef struct hash {
    Dados vetor[TAM_VETOR];
    int ocupado[TAM_VETOR]; // 0 = livre, 1 = ocupado
    No* itens[TAM_VETOR];   // para colisões
    int qtd;                // posições ocupadas
} Hash;

Hash* criaHash();
void liberaHash(Hash* h);
int funcaoHash(int cod);
int inserir(Hash* h, Dados d);
int buscar(Hash* h, int cod, Dados* d, int* passos);
void analiseFinal(Hash* h);