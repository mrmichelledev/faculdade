#define TAM 256

typedef struct no{
    unsigned char caracter;
    int frequencia;
    struct no *esq, *dir, *prox;
}No;

typedef struct{
    No *inicio;
    int tam;
} Lista;

Lista* criaLista();
void iniciaTab(unsigned int tab[]);
void contaFreq(unsigned char texto[], unsigned int tab[]);

void inserirOrdenado(Lista* li, No* no);
void preencherLista(unsigned int tab[], Lista* li);
void imprime(Lista* li);

No* removeInicio(Lista* li);
No* montarArvore(Lista* li);
void imprimeArvore(No* raiz, int tam);

void gerarCodigos(No* raiz, char* codigo, int topo, char codigos[][TAM]);
void liberaArvore(No* raiz);
void codificaTexto(unsigned char texto[], char codigos[][TAM]);
