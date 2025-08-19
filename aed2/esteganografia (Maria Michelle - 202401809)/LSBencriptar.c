#include "LSBesteganografia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//essa funcao vai abrir uma imagem para extrair informacoes
void open_image(FILE *image_file, unsigned char **image_data, long *image_size) {
    
    fseek(image_file, 0, SEEK_END);
    *image_size = ftell(image_file); 
    fseek(image_file, 0, SEEK_SET);

    *image_data = (unsigned char *)malloc(*image_size);
    fread(*image_data, 1, *image_size, image_file);

}

//modifica o último bit de um byte
void hide_bit(unsigned char *byte, unsigned char bit) {
    *byte &= 0xFE;        // Zera o ultimo bit
    *byte |= (bit & 1);   // Define o último bit como o valor do bit da mensagem
}

//escondeendo a mensagem na imagem
void hide_message(unsigned char *image_data, long image_size, const char *message) {
    long data_index = HEADER_SIZE; // Começar depois do cabeçalho
    char full_message[1024];

    // Prepara a mensagem: tamanho + delimitador + mensagem
    snprintf(full_message, sizeof(full_message), "%ld%s%s", strlen(message), DELIMITER, message);

    for (i = 0; i < strlen(full_message); i++) {
        unsigned char current_char = full_message[i];
        for (bit = 7; bit >= 0; bit--) {
            if (data_index >= image_size) {
                printf("Imagem nao tem espaco suficiente para esconder toda a mensagem.\n");
                return;
            }
            unsigned char message_bit = (current_char >> bit) & 1;
            hide_bit(&image_data[data_index], message_bit);
            data_index++;
        }
    }
}

// Função principal para criptografar a mensagem na imagem
void encrypt_text_to_image(const char *text_to_hide) {
    FILE *input_image = fopen(IMAGE_FILE, "rb");
    if (!input_image) {
        perror("Erro ao abrir a imagem");
        return;
    }

    FILE *output_image = fopen(STEG_IMAGE_FILE, "wb");
    if (!output_image) {
        perror("Erro ao criar a imagem de saida");
        fclose(input_image);
        return;
    }

    unsigned char *image_data = NULL;
    long image_size = 0;
    open_image(input_image, &image_data, &image_size);

    // Esconde a mensagem na imagem
    hide_message(image_data, image_size, text_to_hide);

    // Escreve a imagem modificada
    fwrite(image_data, 1, image_size, output_image);

    fclose(input_image);
    fclose(output_image);
    free(image_data);
}