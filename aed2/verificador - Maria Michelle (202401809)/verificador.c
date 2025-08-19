#include <stdio.h>
#include <string.h>
#include "verificador.h"

void iniciaPilha(Pilha *p) {
    p->topo = -1;
}

bool pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

bool pilhaCheia(Pilha *p) {
    return p->topo == MAX_PILHA - 1;
}

bool push(Pilha *p, char c, TipoToken t) {
    if (pilhaCheia(p)) return false;
    p->topo++;
    p->itens[p->topo] = c;
    p->tipos[p->topo] = t;
    return true;
}

bool pop(Pilha *p, char *c, TipoToken *t) {
    if (pilhaVazia(p)) return false;
    *c = p->itens[p->topo];
    *t = p->tipos[p->topo];
    p->topo--;
    return true;
}

bool corresponde(char abre, char fecha) {
    return (abre == '(' && fecha == ')') ||
           (abre == '{' && fecha == '}') ||
           (abre == '[' && fecha == ']') ||
           (abre == '\"' && fecha == '\"') ||
           (abre == '\'' && fecha == '\'');
}

void verificaLinha(char *linha, int numLinha, Pilha *p, bool *in_string, bool *in_char) {
    int i, len = strlen(linha);
    for (i = 0; i < len; i++) {
        char c = linha[i];

        if (*in_string) {
            if (c == '\"') {
                char topo;
                TipoToken tipo;
                if (!pop(p, &topo, &tipo) || tipo != ASPAS_DUPLAS) {
                    printf("Erro linha %d: aspas duplas fechando incorretamente\n", numLinha);
                }
                *in_string = false;
            }
            continue;
        }

        if (*in_char) {
            if (c == '\'') {
                char topo;
                TipoToken tipo;

                if (!pop(p, &topo, &tipo) || tipo != ASPAS_SIMPLES)
                    printf("Erro linha %d: aspas simples fechando incorretamente\n", numLinha);
                
                *in_char = false;
            }
            continue;
        }

        if (c == '(')
            push(p, c, PARENTESE);

        else if (c == '{')
            push(p, c, CHAVE);

        else if (c == '[')
            push(p, c, COLCHETE);

        else if (c == '\"') {
            push(p, c, ASPAS_DUPLAS);
            *in_string = true;

        } else if (c == '\'') {
            push(p, c, ASPAS_SIMPLES);
            *in_char = true;

        } else if (c == ')' || c == '}' || c == ']') {
            char topo;
            TipoToken tipo;

            if (!pop(p, &topo, &tipo)) 
                printf("Erro linha %d: '%c' fechado sem correspondente\n", numLinha, c);
            
            else if (!corresponde(topo, c))
                printf("Erro linha %d: '%c' nao corresponde ao aberto '%c'\n", numLinha, c, topo);
            
        }
    }

    if (strstr(linha, "#include")) {
        if (!(strstr(linha, "#include <") || strstr(linha, "#include \"")))
            printf("Erro linha %d: sintaxe invalida no #include\n", numLinha);
    }

    if (strstr(linha, "printf(") || strstr(linha, "scanf(")) {
        int pos = strlen(linha) - 1;

        while (pos >= 0 && (linha[pos] == ' ' || linha[pos] == '\n' || linha[pos] == '\t')) pos--;

        if (pos < 0 || linha[pos] != ';') 
            printf("Erro linha %d: printf/scanf deve terminar com ';'\n", numLinha);
    }

    if (strstr(linha, "if") || strstr(linha, "for") || strstr(linha, "while") || strstr(linha, "switch"))
        if (!strchr(linha, '(') || !strrchr(linha, ')'))
            printf("Erro linha %d: comando de controle sem parenteses corretos\n", numLinha);
    
}
