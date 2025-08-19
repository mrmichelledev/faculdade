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

#define MAX 100

int i;

typedef struct pilha Pilha;

typedef struct{
    unsigned int num;
} elemento;

void clear();
void proximo();

Pilha* cria_pilha();
void inicia_pilha(Pilha* p);
void libera_pilha(Pilha* pilha1);
int tamanho_pilha(Pilha* pilha1);
int pilha_vazia(Pilha* pilha1);
int pilha_cheia(Pilha* pilha1);
int insere_pilha(Pilha* pilha1, elemento vetNum); //push
int remove_pilha(Pilha* pilha1); //pop
void inverte_pilha(Pilha* pilha1, Pilha* pilha2);
int consulta_topo_pilha(Pilha* pilha1, elemento* vetNum);
void imprime_pilha(Pilha* pilha1, Pilha* pilha2);