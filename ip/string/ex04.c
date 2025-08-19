#include <stdio.h>
#include <string.h>

// Função para contar o número de letras diferentes entre duas palavras
int count_diferentes(char* word1, char* word2) {
    int diferentes = 0, i;
    for ( i = 0; word1[i] != '\0' && word2[i] != '\0'; i++) {
        if (word1[i] != word2[i]) {
            diferentes++;
        }
    }
    return diferentes;
}

// Função para identificar o número correspondente à palavra fornecida
int identify_number(const char* word) {
    if (strlen(word) == 3) {
        if (count_diferentes(word, "one") <= 1) {
            return 1;
        } else if (count_diferentes(word, "two") <= 1) {
            return 2;
        }
    } else if (strlen(word) == 5) {
        if (count_diferentes(word, "three") <= 1) {
            return 3;
        }
    }
}

int main() {
    int n, i;
    char word[6]; // Tamanho máximo das palavras é 5, mais o terminador nulo

    scanf("%d", &n);
    
    for ( i = 0; i < n; i++) {
        scanf("%s", word);
        int number = identify_number(word);
        printf("%d\n", number);
    }

    return 0;
}