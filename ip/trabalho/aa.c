#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 50

void limpador() //função para limpar a tela do jogo
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


int main()
{
	char letra, lacuna[50]="";
	int j = 0, a, i, ii, vida=0, cont, venceu=0;
	char word[MAX_WORDS][MAX_WORD_LENGTH] = {
        "macaco",
        "draco",
        "computaria",
        "pantera negra",
        "league of legends",
		"tudo incluso",
		"seu jorge",
		"hebert top",
		"aquariano nato",
		"amiga da minha mulher",
    };

	char dica[MAX_WORDS][MAX_WORD_LENGTH] = {
        "animal",
        "inf",
        "meme de Ti",
        "filme",
        "jogo",
		"TI",
		"cantor",
		"melhor professor do inf",
		"moedas",
		"música",
    };

    char wordextra[50] = "pneumoultramicroscopicossilicovulcanoconiótico";
    char wordextra2[50] = "asdfghjklñ";

	
	while( j < MAX_WORDS){

		vida=7;

		for(i=0; i<strlen(word[j]); i++)
		{
			if(word[j][i]!=' '){
			lacuna[i] = '_';

			}else {
				lacuna[i] = ' ';
			}
		}

		while(vida > 0 && venceu == 0 )
		{
			limpador();
			printf("Dica: %s\n", dica[j]);
			printf("Quantidade de letras: %d\n", strlen(word[j]));
			printf("Vidas: %d\n\n", vida);

			printf(" ____\n");
			printf("|   |\n");
			printf("|   O\n");
			printf("|  /|\\\n");
			printf("|  / \\\n");
			printf("======= ");
			printf("%s", lacuna);
			printf("\n\n");

			printf("Digite uma letra: ");
			letra = getch();

			printf("%c\n", letra);

			
			for(a=0; a<strlen(word[j]); a++)
			{
				if(word[j][a]==letra){
					lacuna[a] = letra;
					cont++;
				}
			}

			if(cont==0)
			{
				printf("Voce errou uma letra!\n");
				vida--;
				Sleep(500);
			}

			if(cont>0)
			{
				printf("Voce acertou uma letra!\n");
				Sleep(500);
			}
			
			if(vida == 0) venceu=-1;

			if(strcmp(word[j], lacuna)<=0) venceu=1;
			
			cont=0;

			printf("\n");

			if(venceu==1) {
				printf("Parabens! Voce venceu!\n");
				printf("Pressione qualquer tecla para continuar...");
				getch();
				
			}

			if(venceu==-1) {
				printf("Voce perdeu!\n");
				printf("Pressione qualquer tecla para continuar...");
				getch();
			}

			
		}

		for(ii=0; ii<strlen(word[j]); ii++)
		{
			if(word[j][ii]!=' '){
			lacuna[ii]=' ';
			
			}
		}

		if (venceu == 1){
			venceu = 0;
			j++;
		} else if (venceu == -1){
			venceu = 0;
		}
		
	}

	return 0;
}