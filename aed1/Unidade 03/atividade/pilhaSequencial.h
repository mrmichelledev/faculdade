//Arquivo PilhaSequencial.h
typedef struct pilha Pilha;

#define MAX 100

//elemento da pilha
struct aluno{
    int matricula;
    char nome[30];
    float media;
};

Pilha* cria_pilha();
void libera_pilha(Pilha* pilhinha);
int consulta_topo_pilha(Pilha* pilhinha, struct aluno* Aluno);
int insere_pilha(Pilha* pilhinha, struct aluno Aluno); //push
int remove_pilha(Pilha* pilhinha); //pop
int tamanho_pilha(Pilha* pilhinha);
int pilha_vazia(Pilha* pilhinha);
int pilha_cheia(Pilha* pilhinha);
void imprime_pilha(Pilha* pilhinha);
