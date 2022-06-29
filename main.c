#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

 // ESPAÇO PARA CRIAR FUNÇÕES

 void tabela(int cod, char prod[99], char descri[150], float valor, int quant){

    fprintf(stdout, "   %d", cod);
    fprintf(stdout, "          %s", prod);
    fprintf(stdout, "         %s", descri);
    fprintf(stdout, "           %f", valor);
    fprintf(stdout, "         %d\n", quant);

}


 void relatorioMes(int x){

    char arquivo_csv[50];
    char letra;
    int auxCodvend, auxQtdvend, cnovo;
    char auxDescvend[150];
    char datavend[150],auxdatavend[150];
    float valVvend;


    FILE *arquivo;
    arquivo = fopen("cadastro_de_vendas.txt", "r");

    if (arquivo == NULL)
        return EXIT_FAILURE;


    char nomeRelatorio[100] = "relatorio_mes.csv";

    //CRIA O ARQUIVO
     FILE *pont_arq;
     pont_arq = fopen(nomeRelatorio, "a");

     //POE O CABECALHO
     fprintf(pont_arq, "VENDAS DO MES %d",x);
     fprintf(pont_arq, "\ncodProduto;descricaoProduto;qtdProduto;valorProduto;dataVenda");

    while(!feof(arquivo))
    {
        fscanf(arquivo, "%d\n", &auxCodvend);
        cnovo = auxCodvend;
        fscanf(arquivo, "%s\n", &auxDescvend);
        fscanf(arquivo, "%d\n", &auxQtdvend);
        fscanf(arquivo, "%f\n", &valVvend);
        fscanf(arquivo, "%s\n", &datavend);

        strcpy (auxdatavend,datavend);

        //QUEBRA PRA PEGAR O MES
        int c = 0;
        char *pt;

        pt = strtok(datavend, "-");
        while(pt){
            c++;
            if(c==2){
                //achou o mes, transforma em int
                int num;
                num = strtol(pt, NULL, 10);
                if(num==x){
                    //Imprime no relatorio
                    fprintf(pont_arq, "\n%d;%s;%d;%f;%s;",cnovo,auxDescvend,auxQtdvend,valVvend,auxdatavend);
                }

            }
            pt = strtok(NULL, "-");
        }
    }

    fclose(pont_arq);


    printf("\n O relatorio mensal foi criado com sucesso!");


 }

 void relatorioAno(int x){

    char arquivo_csv[50];
    char letra;
    int auxCodvend, auxQtdvend, cnovo;
    char auxDescvend[150];
    char datavend[150],auxdatavend[150];
    float valVvend;


    FILE *arquivo;
    arquivo = fopen("cadastro_de_vendas.txt", "r");

    if (arquivo == NULL)
        return EXIT_FAILURE;


    char nomeRelatorio[100] = "relatorio_ano.csv";

    //CRIA O ARQUIVO
     FILE *pont_arq;
     pont_arq = fopen(nomeRelatorio, "a");

     //POE O CABECALHO
     fprintf(pont_arq, "VENDAS DO ANO %d",x);
     fprintf(pont_arq, "\ncodProduto;descricaoProduto;qtdProduto;valorProduto;dataVenda");

    while(!feof(arquivo))
    {
        fscanf(arquivo, "%d\n", &auxCodvend);
        cnovo = auxCodvend;
        fscanf(arquivo, "%s\n", &auxDescvend);
        fscanf(arquivo, "%d\n", &auxQtdvend);
        fscanf(arquivo, "%f\n", &valVvend);
        fscanf(arquivo, "%s\n", &datavend);

        strcpy (auxdatavend,datavend);

        //QUEBRA PRA PEGAR O ANO
        int c = 0;
        char *pt;

        pt = strtok(datavend, "-");
        while(pt){
            c++;
            if(c==3){
                //achou o ANO, transforma em int
                int num;
                num = strtol(pt, NULL, 10);
                if(num==x){
                    //Imprime no relatorio
                    fprintf(pont_arq, "\n%d;%s;%d;%f;%s;",cnovo,auxDescvend,auxQtdvend,valVvend,auxdatavend);
                }

            }
            pt = strtok(NULL, "-");
        }
    }

    fclose(pont_arq);


    printf("\n O relatorio anual foi criado com sucesso!");


 }

 void relatorioSomaMes(int x){

    char arquivo_csv[50];
    char letra;
    int auxCodvend, auxQtdvend, cnovo;
    char auxDescvend[150];
    char datavend[150],auxdatavend[150];
    float valVvend;
    float soma = 0;


    FILE *arquivo;
    arquivo = fopen("cadastro_de_vendas.txt", "r");

    if (arquivo == NULL)
        return EXIT_FAILURE;


    char nomeRelatorio[100] = "relatorio_soma_mes.csv";

    //CRIA O ARQUIVO
     FILE *pont_arq;
     pont_arq = fopen(nomeRelatorio, "a");

     //POE O CABECALHO
     fprintf(pont_arq, "SOMATORIO VENDAS DO MES %d",x);

    while(!feof(arquivo))
    {
        fscanf(arquivo, "%d\n", &auxCodvend);
        cnovo = auxCodvend;
        fscanf(arquivo, "%s\n", &auxDescvend);
        fscanf(arquivo, "%d\n", &auxQtdvend);
        fscanf(arquivo, "%f\n", &valVvend);
        fscanf(arquivo, "%s\n", &datavend);

        strcpy (auxdatavend,datavend);

        //QUEBRA PRA PEGAR O MES
        int c = 0;
        char *pt;

        pt = strtok(datavend, "-");
        while(pt){
            c++;
            if(c==2){
                //achou o MES, transforma em int
                int num;
                num = strtol(pt, NULL, 10);
                if(num==x){
                    //soma
                    soma+= valVvend;
                }

            }
            pt = strtok(NULL, "-");
        }
    }

    fprintf(pont_arq, "\nSOMA:;R$%f;",soma);

    fclose(pont_arq);


    printf("\n O relatorio de soma do mes foi criado com sucesso!");


 }

int main(){
    setlocale(LC_ALL, "Portuguese"); //PERMITE ACENTOS

    //DEFINICAO DE VARIAVEIS

    //BLOCO CADASTRO DE PRODUTOS
    int band = 1;
    int auxCod, auxQtd, auxD, auxM, auxA;
    int novoQtd = 0;
    char auxDesc[150];
    char teste[150];
    char data[10];
    float valU, valV;

    //BLOCO CADASTRO DE VENDA
    int prosseg = 1;
    int auxCodvend = 0, auxQtdvend = 0;
    char auxDescvend[150];
    char datavend[100];
    float valVvend = 0;

    //BLOCO TELA DE VISUALIZACAO
    char line[99999];
    int codArq;
    int cnovo;
    int qtdArq;
    char descArq[99999];
    char dtArq[99999];
    float valUArq;
    float valVArq;

    //BLOCO RELATORIO
    int band1;
    int band2;
    int mesrelat;
    int anorelat;

    int id; // VARIAVEL PARA PEGAR ID DO FUNCIONÁRIO
    int a; // PEGAR  A OPCAO

    printf("LEIA O README ANTES DE INICIAR\n");
    printf("______________________________ \n");
    printf("|                            | \n");
    printf("| Insira o ID do funcionario | \n");
    printf("|                            | \n");
    printf("             ");
    scanf("%d", &id);
    printf("|                            | \n");
    printf("|                            | \n");
    printf("|____________________________|\n");

    // IF PARA VER SE O FUNCIONARIO VAI SER DE CADASTROS
    if(id == 1){

        printf("______________________________ \n");
        printf("|                            | \n");
        printf("|    1. Cadastrar produto    | \n");
        printf("|    2. Cadastrar venda      | \n");
        printf("|                            | \n");
        printf("             ");
        scanf("%d", &a);
        printf("|                            | \n");
        printf("|                            | \n");
        printf("|____________________________|\n");

            // IF PARA ENTRAR NO CADASTRO DE PRODUTOS
            if(a == 1){

                printf("TELA Cadastrar produtos\n");

                //ABRE O DOC COM OS PRODUTOS
                FILE *pont_arq;
                pont_arq = fopen("bancoProd.txt", "a");


                //VALIDA SE ACHOU
                if(pont_arq == NULL)
                {
                printf("Erro na abertura do arquivo!");
                return 1;
                }

                //BLOCO LOOP PARA POPULAR O BANCO DE PRODUTOS
                do{
                    printf("Insira o codigo: ");
                    scanf("%d", &auxCod);
                    printf("Insira a descricao: ");
                    scanf("%s", &auxDesc);
                    printf("Insira a quantidade: ");
                    scanf("%d", &auxQtd);
                    novoQtd = auxQtd;
                    printf("Insira o valor unitario: ");
                    scanf("%f", &valU);
                    printf("Insira o valor de venda: ");
                    scanf("%f", &valV);
                    printf("Insira a data de cadastro (dd-mm-yyyy): ");
                    scanf("%s", &data);

                //COLOCA NO ARQUIVO
                fprintf(pont_arq, "%d\n%s\n%d\n%f\n%f\n%s\n",auxCod,auxDesc,novoQtd,valU,valV,data);

                //FECHA O ARQUIVO
                fclose(pont_arq);


                //VALIDA SE ELE QUER CONTINUAR
                printf("Dados gravados com sucesso! Deseja inserir um novo produto? (1- SIM, 2-NAO):");
                scanf("%d",&band);

                }while(band==1);

                return 0;

                //FIM BLOCO PARA POPULAR O BANCO DE PRODUTOS


            } else {
                // IF PARA ENTRAR NO CADASTRO DE VENDA
                if(a == 2){
                    printf("TELA Cadastrar vendas\n");
                    //BLOCO PARA CADASTRAR VENDA

                    FILE *pont_arqvenda;

                    //ABRE O BANCO DE VENDOS
                    pont_arqvenda = fopen("cadastro_de_vendas.txt", "a");


                    //VALIDA SE ACHOU O ARQUIVO
                     if(pont_arqvenda == NULL)
                        {
                        printf("Erro na abertura do arquivo!");
                        return 1;
                        }

                    do{
                        printf("Insira o codigo: ");
                        scanf("%d", &auxCodvend);

                        printf("Insira a descricao: ");
                        scanf("%s", auxDescvend);

                        printf("Insira a quantidade: ");
                        scanf("%d", &auxQtdvend);

                        printf("Insira o valor de venda: ");
                        scanf("%f", &valVvend);

                        printf("Insira a data de cadastro (dd-mm-yyyy): ");
                        scanf("%s", datavend);

                    fprintf(pont_arqvenda, "%d\n%s\n%d\n%.2f\n%s\n",auxCodvend,auxDescvend,auxQtdvend,valVvend,datavend);

                    fclose(pont_arqvenda);

                    //COLOCA NO ARQUIVO
                    printf("Dados gravados com sucesso! Deseja inserir uma nova venda? (1- SIM, 2-NAO):");

                    //FECHA O ARQUIVO
                     scanf("%d",&prosseg);

                    }while(prosseg==1);


                    //FIM BLOCO CADASTRAR VENDA

                }
                // ELSE CASO ELE NÃO COLOQUE 1 OU 2
                else {
                    printf("opcao invalida!\n");
                    return 0;
                }
            }

    } else {
        // IF PARA VER SE O FUNCIONARIO VAI SER DE VISUALIZAÇÃO
        if(id == 2){

            //BLOCO PARA TRAZER OS DADOS PRO USUARIO

            //ABRE O BANCO DE PRODUTOS
            FILE *arquivo;
            arquivo = fopen("bancoProd.txt", "r");

            if (arquivo == NULL)
                return EXIT_FAILURE;

            //MONTA A CABECALHO ANTES DE ENTRAR NO LOOP
            printf("****************************** \n");
            printf("*  ID  *     PRODUTO     *          DESCRICAO          *     VALOR     *  QUANTIDADE  *  \n");
            printf("****************************** \n");

            while(!feof(arquivo))
            {
                fscanf(arquivo, "%d\n", &codArq);
                cnovo = codArq;
              	fscanf(arquivo, "%s\n", &descArq);
                fscanf(arquivo, "%d\n", &qtdArq);
                fscanf(arquivo, "%f\n", &valUArq);
                fscanf(arquivo, "%f\n", &valVArq);
                fscanf(arquivo, "%s\n", &dtArq);

                tabela(cnovo,descArq,descArq,valUArq,qtdArq);


            }
            printf("\n");

                  printf("___________\n");
                        printf("|                               |\n");
                        printf("| 1. GERAR RELATORIO VENDAS            |\n");
                        printf("| 2. SAIR                       |\n");
                        printf("  OPCAO: ");
                        scanf("%d", &band1);
                        printf("|___________|\n");

                        if(band1 == 1){
                            printf("\nTIPOS DE RELATORIO:\n");
                            printf("1 - Relatorio de vendas mensais\n");
                            printf("2 - Relatorio de vendas anuais\n");
                            printf("3 - Somatoria mensal\n");
                            printf("OPCAO: ");
                            scanf("%d", &band2);

                            //RELATORIO MENSAL
                            if(band2 == 1){
                                printf("\n Escolha o mes (1 - 12): ");
                                scanf("%d", &mesrelat);
                                relatorioMes(mesrelat);
                            //RELATORIO ANUAL
                            }else if(band2 == 2){
                                printf("\n Escolha o ano (YYYY): ");
                                scanf("%d", &anorelat);
                                relatorioAno(anorelat);
                            //SOMA DE VENDAS EM UM MES
                            }else if(band2==3){
                                printf("\n Escolha o mes (1 - 12): ");
                                scanf("%d", &mesrelat);
                                relatorioSomaMes(mesrelat);
                            }
                            else{
                                printf("opcao invalida");
                                return 0;
                            }

                        }
                        if(band1 == 2){
                            exit(0);
                        }


        } else {
            //NÃO INSERIU UM ID VÁLIDO
            printf("ID Inválido! \n");
        }
    }

    return 0;
}
