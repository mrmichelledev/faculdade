// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "huffman.h"

int main(){
    setlocale(LC_ALL, "Portuguese");

    Lista* li = criaLista();
    int i;
    unsigned int freq[TAM];
    unsigned char texto[] = "O algoritmo de Huffman é uma técnica de compressão de dados sem perdas que atribui códigos binários de comprimento variável aos caracteres de um arquivo, com base na frequência com que aparecem. Os caracteres mais frequentes recebem códigos menores, enquanto os menos frequentes recebem códigos maiores. O processo começa com a contagem da frequência de cada caractere no texto original. Em seguida, constrói-se uma árvore binária onde cada folha representa um caractere, e o caminho da raiz até a folha determina o código binário correspondente. Para criar essa árvore, os dois caracteres com menor frequência são combinados em um nó pai com peso igual à soma de suas frequências. Esse processo se repete até que todos os nós tenham sido agrupados em uma única árvore. Por exemplo, na string \"ABBCCCDDDD\", temos as frequências: A aparece 1 vez, B 2 vezes, C 3 vezes e D 4 vezes. A construção da árvore começa juntando os nós de menor frequência — A (1) e B (2) — resultando em um novo nó com peso 3. Esse novo nó é então combinado com C (3), formando um nó de peso 6. Por fim, esse nó de peso 6 é combinado com D (4), formando a árvore completa com peso 10. A partir dessa árvore, os códigos binários são gerados ao percorrê-la: cada vez que o caminho segue para a esquerda, adiciona-se um 0; para a direita, um 1. Assim, os códigos podem ser, por exemplo: A = 000, B = 001, C = 01, D = 1. A string original é então codificada substituindo-se cada caractere por seu respectivo código, resultando em uma sequência binária compactada, como \"0000010010101011111\". A principal vantagem do algoritmo de Huffman é sua capacidade de reduzir significativamente o tamanho de arquivos com muitos caracteres repetidos, mantendo a integridade dos dados. No entanto, ele não é tão eficiente quando os caracteres ocorrem com frequência uniforme, e também requer que a árvore de Huffman (ou a tabela de códigos) seja armazenada ou transmitida junto com os dados compactados para permitir a decodificação correta.";

    printf("\n\n        ALGORITMO HUFFMAN        \n");
    printf("-----------------------------------------\n\n");    

    iniciaTab(freq);
    contaFreq(texto, freq);

    preencherLista(freq, li);
    imprime(li);

    No* arvore = montarArvore(li);
    printf("\nArvore de Huffman:\n");
    imprimeArvore(arvore, 0);

    // Gerar códigos
    char codigos[TAM][TAM];
    char codigo[TAM];
    for(i = 0; i < TAM; i++)
        codigos[i][0] = '\0';

    gerarCodigos(arvore, codigo, 0, codigos);

    printf("\nCodigos Huffman:\n");
    for (i = 0; i < TAM; i++) {
        if (codigos[i][0] != '\0') {
            printf("'%c': %s\n", i, codigos[i]);
        }
    }

    codificaTexto(texto, codigos);

    liberaArvore(arvore);
    free(li);

    return 0;
}
