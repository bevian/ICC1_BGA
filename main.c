

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 // ESPAÇO PARA CRIAR FUNÇÕES

 void tabela(int cod, char prod[99], char descri[150], float valor, int quant){

    fprintf(stdout, "   %d", cod);
    fprintf(stdout, "          %s", prod);
    fprintf(stdout, "         %s", descri);
    fprintf(stdout, "           %f", valor);
    fprintf(stdout, "         %d\n", quant);

}

/*
 void relatorioMes(int x){

    char arquivo_csv[50];
    char letra;
    int auxCodvend, auxQtdvend, cnovo;
    char auxDescvend[150];
    char datavend[150];
    float valVvend;


    //BUSCA QUAL A CORRESPONDENCIA
    if(x==1){
          char mes[2] = "01";
    }else
     if(x==2){
          char mes[2] = "02";
    }
     if(x==3){
          char mes[2] = "03";
    }else
     if(x==4){
          char mes[2] = "04";
    }else
     if(x==5){
          char mes[2] = "05";
    }else
     if(x==6){
          char mes[2] = "06";
    }else
     if(x==7){
          char mes[2] = "07";
    }else
     if(x==8){
          char mes[2] = "08";
    }else
     if(x==9){
          char mes[2] = "09";
    }else
     if(x==10){
          char mes[2] = "10";
    }else
     if(x==11){
          char mes[2] = "11";
    }else
     if(x==12){
          char mes[2] = "12";
    }


    FILE *arquivo;
    arquivo = fopen("cadastro_de_vendas.txt", "r");

    if (arquivo == NULL)
        return EXIT_FAILURE;

    char nomeRelatorio[100] = "relatorio_mes_1.csv";

    //CRIA O ARQUIVO
     FILE *pont_arq;
     pont_arq = fopen(nomeRelatorio, "a");

     //POE O CABECALHO
     fprintf(pont_arq, "codProduto;descricaoProduto;qtdProduto;valorProduto;dataProduto");

    while(!feof(arquivo))
    {
        fscanf(arquivo, "%d\n", &auxCodvend);
        cnovo = auxCodvend;
        fscanf(arquivo, "%s\n", &auxDescvend);
        fscanf(arquivo, "%d\n", &auxQtdvend);
        fscanf(arquivo, "%f\n", &valVvend);
        fscanf(arquivo, "%s\n", &datavend);

        printf("%d\n",cnovo);
        printf("%s\n",auxDescvend);
        printf("%d\n",auxQtdvend);
        printf("%f\n",valVvend);
        printf("%s\n",datavend);

        //QUEBRA PRA PEGAR O MES
        int c = 0;
        char *pt;

        pt = strtok(datavend, "-");
        while(pt){
            printf("token: %s\n", pt);
            c++;
            if(c==2){
                //achou o mes
                if(pt==mes){
                    printf("achei");
                    //Imprime no relatorio
                    return 0;
                }
                 printf(" n achei");
                    return 0;

            }
            pt = strtok(NULL, "-");
        }

        return 0;

        fprintf(pont_arq, "\n%d;%s;%d;%f;%s;",cnovo,auxDescvend,auxQtdvend,valVvend,datavend);
    }

    fclose(pont_arq);


    printf("\n O relatorio foi criado com sucesso!");


 }*/

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil"); //PERMITE ACENTOS

    int id; // VARIAVEL PARA PEGAR ID DO FUNCIONÁRIO

    printf("______________________________ \n");
    printf("|                            | \n");
    printf("| Insira o ID do funcionário | \n");
    printf("|                            | \n");
    printf("             ");
    scanf("%d", &id);
    printf("|                            | \n");
    printf("|                            | \n");
    printf("|____________________________|\n");

    // IF PARA VER SE O FUNCIONARIO VAI SER DE CADASTROS
    if(id == 1){

        int a;

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

            // IF PARA ENTRAR NO CADASTRO DE PRODUTOS (BIA)
            if(a == 1){

                printf("TELA Cadastrar produtos \n");


                FILE *pont_arq;

                //EXECUTAR ISSO AQUI PRA CRIAR O ARQUIVO (PRIMEIRA EXECUCAO)

                /*
                pont_arq = fopen("bancoProd.txt", "a");

                fclose(pont_arq);

                printf("O arquivo foi criado com sucesso!");

                return 0;
                */


                int band = 1;
                int auxCod, auxQtd, auxD, auxM, auxA;
                int novoQtd = 0;
                char auxDesc[150];
                char teste[150];
                char data[10];
                float valU, valV;

                pont_arq = fopen("bancoProd.txt", "a");


                if(pont_arq == NULL)
                {
                printf("Erro na abertura do arquivo!");
                return 1;
                }

                //BLOCO LOOP PARA POPULAR
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

                fprintf(pont_arq, "%d\n%s\n%d\n%f\n%f\n%s\n",auxCod,auxDesc,novoQtd,valU,valV,data);

                fclose(pont_arq);


                printf("Dados gravados com sucesso! Deseja inserir um novo produto? (1- SIM, 2-NAO):");
                scanf("%d",&band);

                }while(band==1);

                return 0;

                //FIM BLOCO PARA POPULA


            } else {
                // IF PARA ENTRAR NO CADASTRO DE VENDA
                if(a == 2){
                    printf("Cadastrar vendas \n");
                    //BLOCO PARA CADASTRAR VENDA (BRENO)

                    FILE *pont_arqvenda;

                    pont_arqvenda = fopen("cadastro_de_vendas.txt", "a");

                     int prosseg = 1;
                     int auxCodvend = 0, auxQtdvend = 0;
                     char auxDescvend[150];
                     char datavend[100];
                     float valVvend = 0;


                     if(pont_arqvenda == NULL)
                                    {
                                    printf("Erro na abertura do arquivo!");
                                    return 1;
                                    }

                    do{
                        printf("Insira o código: ");
                        scanf("%d", &auxCodvend);

                        printf("Insira a descrição: ");
                        scanf("%s", auxDescvend);

                        printf("Insira a quantidade: ");
                        scanf("%d", &auxQtdvend);

                        printf("Insira o valor de venda: ");
                        scanf("%f", &valVvend);

                        printf("Insira a data de cadastro (dd-mm-yyyy): ");
                        scanf("%s", datavend);

                    fprintf(pont_arqvenda, "%d\n%s\n%d\n%.2f\n%s\n",auxCodvend,auxDescvend,auxQtdvend,valVvend,datavend);

                    fclose(pont_arqvenda);

                    printf("Dados gravados com sucesso! Deseja inserir uma nova venda? (1- SIM, 2-NAO):");

                     scanf("%d",&prosseg);

                    }while(prosseg==1);


                    //FIM BLOCO CADASTRAR VENDA (BRENO)

                }
                // ELSE CASO ELE NÃO COLOQUE 1 OU 2
                else {
                    printf("opção inválida! \n");
                }
            }

    } else {
        // IF PARA VER SE O FUNCIONARIO VAI SER DE VISUALIZAÇÃO (BIA)
        if(id == 2){

            //BLOCO PARA TRAZER OS DADOS DO TXT

            char line[99999];
            int codArq;
            int cnovo;
            int qtdArq;
            char descArq[99999];
            char dtArq[99999];
            float valUArq;
            float valVArq;


            FILE *arquivo;
            arquivo = fopen("bancoProd.txt", "r");

            if (arquivo == NULL)
                return EXIT_FAILURE;

            //MONTA A TABELA AQUI, USANDO ESSAS VARIAVEIS
            printf("****************************** \n");
            printf("*  ID  *     PODUTO     *          DESCRICAO          *     VALOR     *  QUANTIDADE  *  \n");
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

                /*
                printf("%d\n",cnovo);
                printf("%s\n",descArq);
                printf("%d\n",cnovo);
                printf("%f\n",valUArq);
                printf("%f\n",valVArq);
                printf("%s\n",dtArq);
                */


                tabela(cnovo,descArq,descArq,valUArq,qtdArq);


            }

            //FIM BLOCO PRA TRAZER OS DADOS DO TXT

             //BLOCO DE VISUALIZACAO DAS VENDAS (ADRIANO)


             //FIM BLOCO VISUALIZACAO DAS VENDAS

            //TALVEZ COLOCAR OPCAO DE GERAR RELATORIO AQUI DE VENDAS (ANDREGHEIT)
              //RELATORIO ANDREGHT
                int band1;
                int band2;
                int mesrelat;
                  printf("___________\n");
                        printf("|                               |\n");
                        printf("| 1. GERAR RELATORIO            |\n");
                        printf("| 2. SAIR                       |\n");
                        printf("  OPCAO: ");
                        scanf("%d", &band1);
                        printf("|___________|\n");

                        if(band1 == 1){
                            printf("\nTIPOS DE RELATORIO:\n");
                            printf("1 - Relatorio de vendas mensais\n");
                            printf("2 - Relatorio de vendas anuais\n");
                            printf("3 - lucro mensal\n");
                            printf("OPCAO: ");
                            scanf("%d", &band2);

                            if(band2 == 1){
                                printf("\n Escolha o mês (1 - 12): ");
                                scanf("%d", &mesrelat);
                                //relatorioMes(mesrelat);
                            }

                        }
                        if(band1 == 2){
                            exit(0);
                        }



                //FIM RELATORIO ANDREGHT
        } else {
            //NÃO INSERIU UM ID VÁLIDO
            printf("ID Inválido! \n");
        }
    }

    return 0;
}
