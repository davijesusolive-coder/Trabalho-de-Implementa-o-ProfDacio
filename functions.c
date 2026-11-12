#include <stdio.h>
#include <string.h>
#include "estruturas.h"

// Função de exibir menu!

int exibir_menu(void) {
    int opcao;

    printf("\n");
    printf("====================================\n");
    printf("\n");
    printf("            Lojinhas Bahia          \n");
    printf("   Sistema de Cadastro e Filidade   \n");
    printf("\n");
    printf("====================================\n");

    printf("\n");
    printf("====================================\n");
    printf("\n");
    printf("            [ OPÇÕES ]          \n");
    printf("\n");
    printf("1- Cadastro de Cliente\n");
    printf("2- Registrar Compra\n");
    printf("3- Consultar Cartao fidelidade\n");
    printf("4- Resgatar beneficio\n");
    printf("5- Consultar Sorteio\n");
    printf("6- Listar Clientes\n");
    printf("0- Sair\n");
    printf("\n");
    printf("====================================\n");

    printf("\nEscolha uma opcao: ");

    if (scanf("%d", &opcao) != 1) {
        while (getchar() != '\n');
        return -1;
    }

    return opcao;
}

void cadastrar_cliente(struct Cliente clientes[], int *quantidadeClientes) {
    if (*quantidadeClientes < 100) {
        clientes[*quantidadeClientes].id_cliente = *quantidadeClientes +1;
        clientes[*quantidadeClientes].ativo = 1;
        
        getchar();
        
        printf("\nDigite seu Nome: ");
        fgets(clientes[*quantidadeClientes].nome, 100, stdin);
        
        clientes[*quantidadeClientes].nome[strcspn(clientes[*quantidadeClientes].nome, "\n")] = '\0';
        
        (*quantidadeClientes)++;
        
        printf("\nCliente Cadastrado com Sucesso!");
    } else {
        
        printf("\nLimite de cadastro atingido!");
    }
}


// Função de Cadastro de Cliente
