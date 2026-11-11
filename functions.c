#include <stdio.h>
#include <string.h>
#include "estruturas.h"

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
