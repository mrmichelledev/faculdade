#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(seconds) Sleep((seconds) * 1000)
#else
    #include <termios.h>
    #define SLEEP(seconds) sleep(seconds)
#endif

// Define as configurações de cor da fonte
#define CINZA "\033[1;30m"
#define VERDE "\x1B[92m"
#define RED "\033[1;31m"
#define RESET "\x1B[0m"
#define AZUL "\033[36m"

//Definindo o tamanho do array
#define MAX 50

typedef struct fila Fila;

//elemento da fila
typedef struct {
    unsigned int numInt[MAX];
}inteiros;

void clear();
void proximo();
Fila* cria_fila();
void inicia_fila(Fila* filaInt);
void libera_fila(Fila* filaInt);
int tamanho_fila(Fila* filaInt);
int fila_vazia(Fila* filaInt);
int fila_cheia(Fila* filaInt);
int insere_fila(Fila* filaInt, inteiros numInt); 
int remove_fila(Fila* filaInt);
int consulta_primeiro_fila(Fila* filaInt, inteiros* numInt);
void imprime_fila(Fila* filaInt);