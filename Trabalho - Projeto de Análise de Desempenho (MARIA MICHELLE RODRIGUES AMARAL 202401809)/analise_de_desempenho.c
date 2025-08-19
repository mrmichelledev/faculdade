#include <stdio.h>

#define CINZA "\033[38;5;250m"
#define RESET "\033[0m"
#define AMARELO "\033[38;5;228m"

int main(){
    char tipo_processador[50], unidade[5];
    int largura_barramento, dispositivos_conectados, ciclos;
    double frequencia_barramento, frequencia, bandwidth, latencia, penalizacao, banda_efetiva;


    printf("\n                   ANALISE DE DESEMPENHO   \n");
    printf(CINZA"------------------------------------------------------------\n\n"RESET);
    printf("| Preencha os seguintes topicos\n");

    printf("\n\n Tipo de processador:" CINZA " (ex: ARM, x86)\n");
    printf(" > " RESET);
    scanf("%s", tipo_processador);

    //usando do while para validar os valores de entrada > 0
    do{
        printf("\n Largura do barramento de dados:" CINZA " (bits)\n");
        printf(" > " RESET);
        scanf("%d", &largura_barramento);
    } while(largura_barramento < 1);

    do{
        printf("\n Frequencia do barramento:\n");
        printf(" > ");
        scanf("%lf", &frequencia_barramento);
    } while(frequencia_barramento < 1);

    do {
        printf(AMARELO "   MHz ou GHz -> " RESET);
        scanf("%s", unidade);
    } while (strcmp(unidade, "MHz") != 0 && strcmp(unidade, "GHz") != 0 &&
            strcmp(unidade, "mhz") != 0 && strcmp(unidade, "ghz") != 0);

    //convertendo a frequencia do barramento para a unidade escolhida pelo usuario
    if (strcmp(unidade, "GHz") == 0 || strcmp(unidade, "ghz") == 0)
        frequencia = frequencia_barramento * 1e9;
    else if (strcmp(unidade, "MHz") == 0 || strcmp(unidade, "mhz") == 0) 
        frequencia = frequencia_barramento * 1e6;
    

    do{
        printf("\n Numero de dispositivos conectados ao barramento:\n");
        printf(" > ");
        scanf("%d", &dispositivos_conectados);
    } while(dispositivos_conectados < 1);

    do{
        printf("\n Quantidade de ciclos por transferencia:\n");
        printf(" > ");
        scanf("%d", &ciclos);
    } while(ciclos < 1);


    // Taxa de Transferência Teórica (Bandwidth) 
    bandwidth = largura_barramento * frequencia;

    // Latência Estimada (considerando conflitos de acesso) 
    //latencia estimada = latencia basica + atrasos por conflito de acesso 
    latencia = (double)(ciclos * dispositivos_conectados) / frequencia ;

    //Largura de Banda Efetiva (considerando conflitos e atrasos
    penalizacao = 1.0 - (dispositivos_conectados - 1) * 0.05;
    if (penalizacao < 0.1) penalizacao = 0.1;
    banda_efetiva = bandwidth * penalizacao;

    printf("\n\n...\n\n");

    //RESULTADO
    printf("\n\n-------------------------------- FICHA TECNICA --------------------------------\n\n");
    printf(" TIPO DE PROCESSADOR                                      "CINZA"%s\n"RESET, tipo_processador);
    printf(" LARGURA DO BARRAMENTO DE DADOS                           "CINZA"%d bits\n"RESET, largura_barramento);
    printf(" FREQUENCIA DO BARRAMENTO                                 "CINZA"%.2f %s\n"RESET, frequencia_barramento, unidade);
    printf(" NUMERO DE DISPOSITIVOS CONECTADOS AO BARRAMENTO          "CINZA"%d\n"RESET, dispositivos_conectados);
    printf(" QUANTIDADE DE CICLOS POR TRANSFERENCIAS                  "CINZA"%d\n"RESET, ciclos);

    printf("\n\n                          ANALISE DE DESEMPENHO\n\n");

    printf(" TAXA DE TRANSFERENCIA TEORICA                            "CINZA"%.2f Mbps\n"RESET, bandwidth / 1e6);
    printf(" LATENCIA ESTIMADA                                        "CINZA"%.2f ns\n"RESET, latencia * 1e9);
    printf(" CICLOS POR TRANSFERENCIA                                 "CINZA"%d\n"RESET, ciclos);
    printf(" LARGURA DE BANDA EFETIVA                                 "CINZA"%.2f Mbps\n\n\n"RESET, banda_efetiva / 1e6);


    return 0;
}