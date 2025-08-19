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

typedef struct pilha Pilha;

//elemento da pilha
typedef struct {
    unsigned int numInt;
}inteiros;

void clear();
void proximo();

Pilha* cria_pilha();
void inicia_pilha(Pilha* pilhas);
void libera_pilha(Pilha* pilhas);
int tamanho_pilha(Pilha* pilhas);
int pilha_vazia(Pilha* pilhas);
int pilha_cheia(Pilha* pilhas);
int insere_pilha(Pilha* pilhas, inteiros numInt); //push
int remove_pilha(Pilha* pilhas); //pop

int consulta_topo_pilha(Pilha* pilhas, inteiros* numInt);
void imprime_pilha(Pilha* pilhas);