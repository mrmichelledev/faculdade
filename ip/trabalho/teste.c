// 1.macaco/ 2.draco/ 3.computaria/ 4.pantera negra/ 5.league of legends/ 6.tudo incluso/ 7.seu jorge/ 8.hebert top/ 9.aquarino nato/ 10.amiga da minha mulher/  asdfghjklñ/pneumoultramicroscopicossilicovulcanoconiótico 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
    int i,a,cont=0, level = 1,vida=0,venceu=0;
    char lacuna[50]="",letra;
    char word1[50] = "macaco";
    char word2[50] = "draco";
    char word3[50] = "computaria";
    char word4[50] = "pantera negra";
    char word5[50] = "league of legends";
    char word6[50] = "tudo incluso";
    char word7[50] = "seu jorge";
    char word8[50] = "hebert top";
    char word9[50] = "aquariano nato";
    char word10[50] = "amiga da minha mulher";
    char wordextra[50] = "pneumoultramicroscopicossilicovulcanoconiótico";
    char wordextra2[50] = "asdfghjklñ";

    printf("Bem vindo(a) ao modo campanha!");
    

        for(i=0; i<strlen(word1); i++)
        {
            if(word1[i]!=' ') lacuna[i] = '_';
            else lacuna[i] = ' ';
        }
        
        while(vida > 0 && venceu == 0)
        {
            system("cls");
            printf("Dica: animal\n");
            printf("Quantidade de letras: %d\n", strlen(word1));
            printf("Vidas: %d\n\n", vida);

            printf("%s", lacuna);
            printf("\n\n");

            printf("Digite uma letra: ");
            letra = getch();

            printf("%c\n", letra);

            for(a=0; a<strlen(word1); a++)
            {
                if(word1[a]==letra)
                {
                    lacuna[a] = letra;
                    cont++;
                }
            }

            if(cont==0)
            {
                printf("Voce errou uma letra!\n");
                vida--;
            }

            if(cont>0)
            {
                printf("Voce acertou uma letra!\n");
            }
            if(vida == 0) venceu=-1;

            if(strcmp(word1, lacuna)==0) venceu=1;
            cont=0;
        }

 return 0;   
}