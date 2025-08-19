#define MAX 17

typedef struct {
    int tam;
    int vet[MAX];
} heap;

void criaHeap(heap* he);
int pai(int i);
int filhoEsquerda(int i);
int filhoDireita(int i);
void swap(int *a, int *b);
void insere(heap* he, int num);
void maxHeapify(heap* he, int i);
void remover(heap* he);
void consulta(heap* he, int num);
void imprime(heap* he);
