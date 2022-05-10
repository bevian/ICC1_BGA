#include <stdio.h>

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

            } 
            
            // ELSE PARA CADASTRO DE VENDAS
            else {
                printf("Cadastrar vendas \n");
            }

    }
    
    // ELSE CASO O FUNCIONARIO SEJA DE VISUALIZAÇÃO DE ESTOQUE
    else {

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
        
    }


    return 0;
}