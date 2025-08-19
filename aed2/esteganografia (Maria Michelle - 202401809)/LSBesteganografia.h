#include <stdio.h>

//definicoes gerais
#define HEADER_SIZE 54
#define DELIMITER "$"
#define IMAGE_FILE "teste1.bmp"
#define STEG_IMAGE_FILE "hidden_teste.bmp"

int i, bit;

//arquivo LSBencriptar.c
void open_image(FILE *image_file, unsigned char **image_data, long *image_size);
void hide_bit(unsigned char *byte, unsigned char bit);
void hide_message(unsigned char *image_data, long image_size, const char *message);
void encrypt_text_to_image(const char *text_to_hide);

//arquivo LSBdesencriptar.c
void open_imageHidden(FILE *image_file, unsigned char **image_data, long *image_size);
int get_text_size(FILE *image_file);
char get_char(FILE *image_file);
void decrypt_text_from_image();