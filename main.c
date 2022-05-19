#include <stdio.h>
#include <stdlib.h>

 // ESPAÇO PARA CRIAR FUNÇÕES

int main(){

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

            // IF PARA ENTRAR NO CADASTROD DE PRODUTOS
            if(a == 1){
                
                printf("Cadastrar produtos \n");

                FILE *arquivo;

                arquivo = fopen("teste.txt", "w"); 

                if(arquivo == NULL){
                    printf("erro!");
                    exit(0);
                }

                fprintf(arquivo, "Ola estou funcionando \n"); //Exibindo no arquivo

                // Primeiro número 
                int n1;	

                printf("Insira o ID do produto: ");
                scanf("%d", &n1);
                fprintf(arquivo, "ID produto = %d \n", n1);
                fprintf(stdout, "ID produto = %d \n", n1);


            } else {
                // IF PARA ENTRAR NO CADASTRO DE VENDA
                if(a == 2){
                    printf("Cadastrar vendas \n");
                } 
                // ELSE CASO ELE NÃO COLOQUE 1 OU 2
                else {
                    printf("opção inválida! \n");
                }
            }

    } else {
        // IF PARA VER SE O FUNCIONARIO VAI SER DE VISUALIZAÇÃO
        if(id == 2){

            // TABELA DE VISUAL DOS PRODUTOS INSERIDOS NO ESTOQUE
            printf("_________________________________ \n");
            printf("|  ID  |  QUANTIDADE  | OUTROS  | \n");
            printf("|______|______________|_________| \n");
            printf("|      |              |         | \n");
            printf("|      |              |         | \n");
            printf("|      |              |         | \n");
            printf("|      |              |         | \n");
            printf("|      |              |         | \n");
            printf("|______|______________|_________| \n");
        } else {
            //NÃO INSERIU UM ID VÁLIDO
            printf("ID Inválido! \n");
        }   
    }

    return 0;
}