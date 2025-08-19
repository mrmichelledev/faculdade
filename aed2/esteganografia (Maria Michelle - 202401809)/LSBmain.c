#include "LSBesteganografia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 

int main(){
    const char *text_to_hide = "esteganografada";

    printf("Encriptando! Aguarde...\n\n");
    encrypt_text_to_image(text_to_hide);
    Sleep(2000);

    printf("Texto escondido com sucesso na imagem.\n\n");
    Sleep(2000);

    printf("Desencriptando! Aguarde...\n\n");
    Sleep(2000);

    decrypt_text_from_image();

    return 0;
}