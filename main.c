#include <stdio.h>
#include "estruturas.h"
#include "cliente.h"
#include "fidelidade.h"
#include "beneficio.h"
#include "movimentacao.h"
int main(void)
{
    // main.c eh o "dono" dos dados: os arrays sao criados aqui e
    // passados por parametro pra cada modulo mexer neles.
    Cliente clientes[MAX_CLIENTES];
    int totalClientes = 0;

    Fidelidade fidelidades[MAX_CLIENTES];
    int totalFidelidades = 0;

    Movimentacao movimentacoes[MAX_MOVIMENTACOES];
    int totalMovimentacoes = 0;

    int opcao;

    do
    {
        printf("\n===== Sistema de Fidelidade =====\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Registrar Compra\n");
        printf("3. Consultar Cartao Fidelidade\n");
        printf("4. Resgatar Beneficio\n");
        printf("5. Consultar Sorteio\n");
        printf("6. Listar Clientes\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                cadastrarCliente(clientes, &totalClientes, fidelidades, &totalFidelidades);
                break;
            case 2:
                registrarCompra(clientes, totalClientes, fidelidades, totalFidelidades,
                                 movimentacoes, &totalMovimentacoes);
                break;
            case 3:
                consultarCartaoFidelidade(fidelidades, totalFidelidades);
                break;
            case 4:
                resgatarBeneficio(fidelidades, totalFidelidades, movimentacoes, &totalMovimentacoes);
                break;
            case 5:
                consultarSorteio(clientes, totalClientes, fidelidades, totalFidelidades);
                break;
            case 6:
                listarClientes(clientes, totalClientes);
                break;
            case 7:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 7);

    return 0;
}
