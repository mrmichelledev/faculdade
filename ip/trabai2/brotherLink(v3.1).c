#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define o Máximo de contatos
#define MAX 250

// Define as configurações de cor da fonte
#define CINZA "\033[1;30m"
#define VERDE "\x1B[92m"
#define RED "\033[1;31m"
#define RESET "\x1B[0m"

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(seconds) Sleep((seconds) * 1000)
#else
    #include <termios.h>
    #define SLEEP(seconds) sleep(seconds)
#endif

struct contato {
    char nome[50];
    char fone[13];
    char email[254];
};

struct contato contatos[MAX];
int cont = 0;

void clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// desativa a necessidade de apertar enter
void qualquer_tecla(){
    #ifdef _WIN32
        #include <conio.h>
        _getch();
    #else
        #include <termios.h>
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt); // Salva os atributos atuais do terminal
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // Desativa o modo canônico e o eco
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Aplica as novas configurações

        getchar();

        struct termios oldt;
        tcgetattr(STDIN_FILENO, &oldt); // Salva os atributos atuais do terminal
        oldt.c_lflag |= (ICANON | ECHO); // Ativa o modo canônico e o eco
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Aplica as novas configurações
    #endif
}

void creatContato(){
    clear();
    struct contato ctts;
    char op;

    printf("\nRegistre um novo contato incluindo detalhes como nome, telefone e endereco de email.\n\n");

    printf("Nome:\n");
    printf(CINZA "Insira seu nome completo (ex: Joao da Silva).\n" RESET);
    printf(CINZA "Nao inclua caracteres especiais, numeros ou pontuacoes.\n" RESET);
    fgets(ctts.nome, sizeof(ctts.nome), stdin);
    ctts.nome[strcspn(ctts.nome, "\n")] = '\0'; // Remove newline character
    

    printf("\nN telefone:\n");
    printf(CINZA "Digite exatamente 11 digitos numericos (ex: 11987654321).\n" RESET);
    fgets(ctts.fone, sizeof(ctts.fone), stdin);
    ctts.fone[strcspn(ctts.fone, "\n")] = '\0'; // Remove newline character

    printf("\nE-mail:\n");
    printf(CINZA "Insira um formato valido de email (nome@dominio.com).\n" RESET);
    fgets(ctts.email, sizeof(ctts.email), stdin);
    ctts.email[strcspn(ctts.email, "\n")] = '\0'; // Remove newline character

    contatos[cont++] = ctts;
        
    printf("\n\n........................................................\n");
    printf("\tNome: %s\n", ctts.nome);
    printf("\tN telefone: (%c%c) %c %c%c%c%c-%c%c%c%c\n", ctts.fone[0],ctts.fone[1],ctts.fone[2],ctts.fone[3],ctts.fone[4],ctts.fone[5],ctts.fone[6],ctts.fone[7],ctts.fone[8], ctts.fone[9],ctts.fone[10]);
    printf("\tE-mail: %s\n", ctts.email);
    printf("........................................................\n\n");

    printf(VERDE "\nContato salvo!\n" RESET);
    printf("Digite '1' para adicionar um novo contato, ou pressione ENTER para sair.\n");
    op = getchar();
    if (op == '1') {
        getchar();
        creatContato();
        return;
    }
}

void detalharContato(int i){
    i--;
    printf("........................................................\n\n");
    printf(CINZA "\t%d." RESET " %s\n", i+1, contatos[i].nome);
    printf("\tN telefone: (%c%c) %c %c%c%c%c-%c%c%c%c\n", contatos[i].fone[0],contatos[i].fone[1],contatos[i].fone[2],contatos[i].fone[3],
                                                        contatos[i].fone[4],contatos[i].fone[5],contatos[i].fone[6],contatos[i].fone[7],
                                                        contatos[i].fone[8],contatos[i].fone[9],contatos[i].fone[10]);
    printf("\tE-mail: %s\n", contatos[i].email);
    printf("........................................................\n");
}

// Função para listar contatos cadastrados
void listarContatos(){
    clear();
    int i;
    char op;
    if (cont){
        printf("Agenda de Contatos:\n\n");
        printf(".........................................................................................\n");

        for ( i = 0; i < cont; i++){
            printf(CINZA "\t%d." RESET " %s\n", i+1, contatos[i].nome);
        }

            printf(".........................................................................................\n");
            printf(CINZA "Digite o numero do contato para detalhar, ou pressione ENTER para voltar ao menu inicial...\n\n" RESET);

            op = getchar();

            if (op) {getchar(); detalharContato(op - '0');} 
            else return;
    } else{
        while (1){  
            printf(RED "\nNao ha contatos cadastrados!\n" RESET);
            printf("Digite '1' para cadastrar um novo contato, ou pressione ENTER para voltar ao menu inicial...\n\n");
            op = getchar();

            // Limpar o buffer de entrada para capturar apenas a primeira tecla
            while (getchar() != '\n');

            if (op == '1') {
                getchar();
                creatContato();
                return;
            } 
            else if(op == '\n') return;
            else {
                clear();
                printf(RED "\n\nOpcao invalida. Tente novamente.\n" RESET);
                SLEEP (1);
                clear();
            }
        }
    }
    getchar();
}

void buscarContato(){
    clear();
    char buscarNome[50], op;
    int i;

    if(cont == 0){
        printf(RED "\nNao ha contatos cadastrados!\n" RESET);
        printf("Digite '1' para cadastrar um novo contato, ou pressione ENTER para voltar ao menu inicial...\n\n");
        op = getchar();
        if (op == '1') {
            getchar();
            creatContato();
            return;
        } else {
            return;
        }
    }

    printf(CINZA "(obs)Nao e necessario inserir o nome completo para realizar a busca.\n\n" RESET);
    printf("Digite o nome do contato para buscar: ");
    fgets(buscarNome, sizeof(buscarNome), stdin);
    buscarNome[strcspn(buscarNome, "\n")] = '\0';

    for (i = 0; i < cont; i++) {
        if (strstr(contatos[i].nome, buscarNome) != NULL) {
            printf("........................................................\n");
            printf("\tNome: %s\n", contatos[i].nome);
            printf("\tN telefone: (%c%c) %c%c%c%c-%c%c%c%c\n",
                   contatos[i].fone[0], contatos[i].fone[1], contatos[i].fone[2],
                   contatos[i].fone[3], contatos[i].fone[4], contatos[i].fone[5],
                   contatos[i].fone[6], contatos[i].fone[7], contatos[i].fone[8],
                   contatos[i].fone[9], contatos[i].fone[10]);
            printf("\tE-mail: %s\n", contatos[i].email);
            printf("........................................................\n");

            printf(CINZA "Digite '1' para tentar novamente ou qualquer outra tecla para sair.\n" RESET);

            op = getchar();

            if (op == '1') {
                getchar();
                buscarContato();
                return;
            } else{
                return;
            }
        }
    }

    printf(RED "\nNao ha contatos cadastrados com esse nome!\n" RESET);
    printf(CINZA "Digite '1' para tentar novamente ou qualquer outra tecla para sair.\n" RESET);

    op = getchar();

    if (op == '1') {
        getchar();
        buscarContato();
        return;
    } else{
        return;
    }
}

void excluirContato(){
    clear();
    char nomeContato[50], op;
    int i, j;

    //caso não tenha mais contatos salvos
    if(cont == 0){
        printf(RED "\nSem contatos cadastrados!\n" RESET);
        printf("Digite '1' para cadastrar um novo contato, ou pressione ENTER para voltar ao menu inicial...\n\n");
        op = getchar();
        if (op == '1') {
            getchar();
            creatContato();
            return;
        }else{
            return;
        }
    }

    printf("\nDigite o nome do contato para excluir: ");
    fgets(nomeContato, sizeof(nomeContato), stdin);
    nomeContato[strcspn(nomeContato, "\n")] = '\0'; //Remove o caractere de nova linha (\n) do final da string nome, substituindo-o por \0.

    for (i = 0; i < cont; i++) {
        if (strcmp(contatos[i].nome, nomeContato) == 0) {

            //Se o nome for encontrado, move todos os contatos à frente na lista um índice para trás, 
            //sobrescrevendo assim o contato a ser excluído.
            for (j = i; j < cont - 1; j++) {
                contatos[j] = contatos[j + 1];
            }
            cont--;

            printf(VERDE "Contato excluido com sucesso.\n" RESET);
            printf(CINZA "Digite '1' para tentar novamente ou qualquer outra tecla para sair.\n" RESET);

            op = getchar();

            if (op == '1') {
                getchar();
                excluirContato();
                return;
            } else{
                return;
            }
        }
    }

    printf(RED "Contato nao encontrado.\n" RESET);
    printf(CINZA "Digite '1' para tentar novamente, ou qualquer outra tecla para sair.\n" RESET);
    op = getchar();
    if (op == '1') {
        getchar();
        excluirContato();
        return;
    } 
}

void ordenarcontatos(){
    int i, j, k=0;
    for(i=0; i < cont; i++){
        for (j = 1; j < cont; j++)
        {
            if (contatos[i].nome[k])
            {
                 
            }   
        }
    }
}

int menu(){
    int op;
    printf(" _               _   _                 _ _       _    \n");
    printf("| |             | | | |               | (_)     | |   \n");
    printf("| |__  _ __ ___ | |_| |__   ___ _ __  | |_ _ __ | | __\n");
    printf("| '_ \\| '__/ _ \\| __| '_ \\ / _ \\ '__| | | | '_ \\| |/ /\n");
    printf("| |_) | | | (_) | |_| | | |  __/ |    | | | | | |   < \n");
    printf("|_.__/|_|  \\___/ \\__|_| |_|\\___|_|    |_|_|_| |_|_|\\_\\\n");
    printf("\t                                                         \n");
    printf("Bem-vindo ao Sistema de Agenda de Contatos, sua solucao simples e eficiente para gerenciar contatos pessoais e profissionais com facilidade.\n");
    printf("\n");
    printf("...............................................................................\n");
    printf("Selecione uma opcao pelo numero correspondente e pressione Enter para confirmar.\n");
    printf("\t(1) Adicionar Contato\n");
    printf("\t(2) Listar Contatos\n");
    //printf("\t(3) Visualizar Detalhes do Contato\n");
    printf("\t(3) Buscar contato\n");
    printf("\t(4) Excluir Contato\n");
    printf("\t(5) Sair\n");
    printf("...............................................................................\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    getchar();
    return op;
}

int main(){
          
    while(1){
        clear();
        switch(menu()){
            case 1:
                creatContato();
                break;
            case 2:
                listarContatos();
                break;
            /*case 3:
                detalharContato();
                break;*/
            case 3:
                buscarContato();
                break;
            case 4:
                excluirContato();
                break;
            case 5:
                clear();
                printf("Saindo...\n");
                SLEEP(1);
                clear();
                return 0;
            default:
                clear();
                printf("\033[0;31m\n\nOpcao invalida. Tente novamente.\n" RESET);
                SLEEP(1);
        }
    }

    return 0;

}