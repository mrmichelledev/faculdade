#ifndef VERIFICADOR_H
#define VERIFICADOR_H

#include <stdbool.h>

#define MAX_PILHA 1024
#define MAX_LINHA 512

typedef enum {PARENTESE, CHAVE, COLCHETE, ASPAS_DUPLAS, ASPAS_SIMPLES} TipoToken;

typedef struct {
    char itens[MAX_PILHA];
    TipoToken tipos[MAX_PILHA];
    int topo;
} Pilha;

void iniciaPilha(Pilha *p);
bool pilhaVazia(Pilha *p);
bool pilhaCheia(Pilha *p);
bool push(Pilha *p, char c, TipoToken t);
bool pop(Pilha *p, char *c, TipoToken *t);

void verificaLinha(char *linha, int numLinha, Pilha *p, bool *in_string, bool *in_char);

#endif
