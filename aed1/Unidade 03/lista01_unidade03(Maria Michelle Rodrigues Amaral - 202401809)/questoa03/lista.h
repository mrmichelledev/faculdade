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

typedef struct lista Lista;

//elemento da lista
typedef struct {
    unsigned int numInt[MAX];
}inteiros;

unsigned int i, j;

void clear();
void proximo();

Lista* cria_lista();
void inicia_lista(Lista* listaInt);
void libera_lista(Lista* listaInt);
int tamanho_lista(Lista* listaInt);
int lista_vazia(Lista* listaInt);
int lista_cheia(Lista* listaInt);
void ordenar(inteiros* a, inteiros* b);
void ascendente(Lista* listaInt);
int insere_inicio_lista(Lista* listaInt, inteiros numInt);
int insere_meio_lista(Lista* listaInt, inteiros numInt); 
int insere_final_lista(Lista* listaInt, inteiros numInt); 
int remove_inicio_lista(Lista* listaInt);
int remove_meio_lista(Lista* listaInt);
int remove_fim_lista(Lista* listaInt);
int consulta_elemento_valor(Lista* listaInt, int valor);
int consulta_elemento_indice(Lista* listaInt, inteiros* numInt, int indice);
void imprime_lista(Lista* listaInt);
