#include "LSBesteganografia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para abrir a imagem e retornar os dados
void open_imageHidden(FILE *image_file, unsigned char **image_data, long *image_size) {

    fseek(image_file, 0, SEEK_END);
    *image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    *image_data = (unsigned char *)malloc(*image_size);
    fread(*image_data, 1, *image_size, image_file);
    
}

// Função para ler o tamanho do texto escondido
int get_text_size(FILE *image_file) {
    int text_size = 0;
    char curr_char;
    char text_size_str[20] = ""; // tamanho maior pra garantir
    int bit_count;
    unsigned char assembled_byte;
    i = 0;

    while (1) {
        assembled_byte = 0;

        // Monta 1 caractere a partir de 8 bits
        for (bit_count = 0; bit_count < 8; bit_count++) {
            unsigned char byte = fgetc(image_file);
            assembled_byte = (assembled_byte << 1) | (byte & 0x01);
        }

        curr_char = assembled_byte;

        // Verifica se encontrou o delimitador
        if (curr_char == DELIMITER[0]) {
            // Leu o primeiro caractere do delimitador, agora devemos parar
            break;
        }

        // Adiciona o caractere ao string do tamanho
        text_size_str[i++] = curr_char;
    }

    text_size_str[i] = '\0'; // Termina a string com null character
    sscanf(text_size_str, "%d", &text_size);

    return text_size;
}

// Função para extrair um caractere da imagem
char get_char(FILE *image_file) {
    char current_char = 0;
    unsigned char byte;

    // Lê 8 bits (um byte)
    for (bit = 7; bit >= 0; bit--) {
        byte = fgetc(image_file); // lê 1 bit do byte
        current_char |= ((byte & 1) << bit); // reconstrução do byte
    }

    return current_char;
}

// Função principal para decodificar o texto da imagem
void decrypt_text_from_image() {
    FILE *input_image = fopen(STEG_IMAGE_FILE, "rb");
    if (!input_image) {
        perror("Erro ao abrir a imagem");
        return;
    }

    unsigned char *image_data = NULL;
    long image_size = 0;
    open_imageHidden(input_image, &image_data, &image_size);

    fseek(input_image, HEADER_SIZE, SEEK_SET);  // Pular o cabeçalho da imagem

    // Ler o tamanho do texto
    int text_size = get_text_size(input_image);

    // Extrair o texto
    char *decoded_text = (char *)malloc(text_size + 1); // Aloca memória para o texto
    for (i = 0; i < text_size; i++) {
        decoded_text[i] = get_char(input_image);  // Extrai um caractere de cada vez
    }
    decoded_text[text_size] = '\0';  // Adiciona o terminador de string

    // Exibir o texto decodificado
    printf("Texto extraido: %s\n", decoded_text);

    // Fechar os arquivos e liberar a memória
    fclose(input_image);
    free(image_data);
    free(decoded_text);
}