
  
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 // ESPAÇO PARA CRIAR FUNÇÕES

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
                
                printf("Cadastrar produtos \n");

                
                FILE *pont_arq;

                //EXECUTAR ISSO AQUI PRA CRIAR O ARQUIVO (PRIMEIRA EXECUCAO)
                /*
                pont_arq = fopen("bancoICC.txt", "a");

                fclose(pont_arq);

                printf("O arquivo foi criado com sucesso!");
                */

                int band = 1;
                int auxCod = 0, auxQtd = 0, auxD, auxM, auxA;
                char auxDesc[150];
                char teste[150];
                char data[10];
                float valU = 0, valV = 0;

                pont_arq = fopen("bancoICC.txt", "a");


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
                    printf("Insira o valor unitario: ");
                    scanf("%f", &valU);
                    printf("Insira o valor de venda: ");
                    scanf("%f", &valV);
                    printf("Insira a data de cadastro (dd-mm-yyyy): ");
                    scanf("%s", &data);

                fprintf(pont_arq, "%d\n%s\n%d\n%f\n%f\n%s\n",auxCod,auxDesc,auxQtd,valU,valV,data);

                fclose(pont_arq);

                getch();

                printf("Dados gravados com sucesso! Deseja inserir um novo produto? (1- SIM, 2-NAO):");
                scanf("%d",&band);

                }while(band==1);

                //FIM BLOCO PARA POPULA


            } else {
                // IF PARA ENTRAR NO CADASTRO DE VENDA
                if(a == 2){
                    printf("Cadastrar vendas \n");
                    //BLOCO PARA CADASTRAR VENDA (BRENO)


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

            char* palavras[50];
            char produtos [9999][5];
            char line[99999];
            int i =0,numPalavras=0;
            FILE *arquivo;
            arquivo = fopen("bancoICC.txt", "r");

            if (arquivo == NULL)
                return EXIT_FAILURE;

            while(fgets(line, sizeof line, arquivo) != NULL)
            {
                //Adiciona cada palavra no vetor
                palavras[i] = strdup(line);

                i++;

                //Conta a quantidade de palavras
                numPalavras++;
            }

            int j;

            for (j = 0; j < numPalavras; j++)
                printf("\n%s", palavras[j]); //Exibi as palavras que estao no vetor.

            printf("\n\n");

            int k = 0, l=0;
            //faz um loop para montar um array
            for(int i =0; i<numPalavras;i++){
                produtos[k][l] =  palavras[i];
                //nao aparece nada
                printf("%c",produtos[k][l]);
            }

            //FIM BLOCO PRA TRAZER OS DADOS DO TXT

            // TABELA DE VISUAL DOS PRODUTOS INSERIDOS NO ESTOQUE (ADRIANO)
            printf("_________________________________ \n");
            printf("|  ID  |  QUANTIDADE  | OUTROS  | \n");
            printf("|______|______________|_________| \n");
            printf("|      |              |         | \n");
            printf("|      |              |         | \n");
            printf("|      |              |         | \n");
            printf("|      |              |         | \n");
            printf("|      |              |         | \n");
            printf("|______|______________|_________| \n");


             //BLOCO DE VISUALIZACAO DAS VENDAS (ADRIANO)


             //FIM BLOCO VISUALIZACAO DAS VENDAS

            //TALVEZ COLOCAR OPCAO DE GERAR RELATORIO AQUI DE VENDAS (ANDREGHEIT)
        } else {
            //NÃO INSERIU UM ID VÁLIDO
            printf("ID Inválido! \n");
        }   
    }

    return 0;
}