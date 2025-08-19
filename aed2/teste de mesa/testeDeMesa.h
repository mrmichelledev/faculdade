typedef struct No* Arvore;

Arvore* cria_arvore();
void libera_arvore(Arvore* raiz);
int arvore_vazia(Arvore* raiz);
int altura_arvore(Arvore* raiz);
int total_No(Arvore* raiz);
int insere_arvore(Arvore* raiz, int valor);
int remove_arvore(Arvore* raiz, int  valor);