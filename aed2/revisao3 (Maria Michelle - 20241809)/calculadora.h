typedef struct elemento* Pilha;

Pilha* cria_pilha();
void libera_pilha(Pilha* pi);
int empilha(Pilha* pi, float num);
int desempilhar(Pilha* pi, float* valor);
float calcula(float a, float b, char x);
float resolver_expressao(Pilha* pi, char x[]);
