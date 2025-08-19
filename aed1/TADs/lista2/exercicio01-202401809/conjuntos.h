#define CINZA "\033[1;30m"
#define VERDE "\x1B[92m"
#define RED "\033[1;31m"
#define RESET "\x1B[0m"

typedef struct conjunto Conjunto;

void menu();
void clear();

int criaConjunto(Conjunto** c);
int conjuntoVazio(Conjunto* c);
int insereElementoConjunto(int e, Conjunto* c);
int excluirElementoConjunto(int e,Conjunto* c);
int tamanhoConjunto(Conjunto* c);
int maior(int e, Conjunto* c);
int menor(int e, Conjunto* c);
int pertenceConjunto(int e, Conjunto* c);
int conjuntosIdenticos(Conjunto* c1, Conjunto* c2);
int subconjunto(Conjunto* c1, Conjunto* c2);
void mostraConjunto(Conjunto* c);