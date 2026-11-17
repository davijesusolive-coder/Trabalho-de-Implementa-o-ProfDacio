#include <stdio.h>
#include <time.h>
#include "fidelidade.h"
#include "cliente.h"
#include "movimentacao.h"

#define PONTOS_POR_COMPRA 10

void registrarCompra(Cliente clientes[], int totalClientes,
                     Fidelidade fidelidades[], int totalFidelidades,
                     Movimentacao movimentacoes[], int *totalMovimentacoes)
{
    char cpf[15];
    char data[11];
    int indiceCliente;
    int indiceFidelidade;
    time_t agora;
    struct tm *dataAtual;

    printf("\n===== REGISTRAR COMPRA =====\n");
    printf("Digite o CPF do cliente: ");

    if (scanf(" %14s", cpf) != 1) {
        printf("Erro ao ler o CPF.\n");
        return;
    }

    indiceCliente = buscarClientePorCpf(clientes, totalClientes, cpf);

    if (indiceCliente == -1 || clientes[indiceCliente].ativo != 1) {
        printf("Cliente nao encontrado ou inativo.\n");
        return;
    }

    indiceFidelidade = buscarFidelidadePorIdCliente(
        fidelidades, totalFidelidades, clientes[indiceCliente].id_cliente
    );

    if (indiceFidelidade == -1) {
        printf("Cartao de fidelidade nao encontrado ou inativo.\n");
        return;
    }

    if (totalMovimentacoes == NULL ||
        *totalMovimentacoes >= MAX_MOVIMENTACOES) {
        printf("Limite de movimentacoes atingido. Compra nao registrada.\n");
        return;
    }

    agora = time(NULL);
    dataAtual = localtime(&agora);
    if (dataAtual == NULL) {
        printf("Nao foi possivel obter a data. Compra nao registrada.\n");
        return;
    }
    strftime(data, sizeof(data), "%d/%m/%Y", dataAtual);

    fidelidades[indiceFidelidade].pontos += PONTOS_POR_COMPRA;

    registrarMovimentacao(
        movimentacoes,
        totalMovimentacoes,
        clientes[indiceCliente].id_cliente,
        PONTOS_POR_COMPRA,
        "Credito",
        data
    );

    printf("Compra registrada com sucesso!\n");
    printf("Cliente: %s\n", clientes[indiceCliente].nome);
    printf("Pontos adicionados: %d\n", PONTOS_POR_COMPRA);
    printf("Total de pontos: %d\n",
           fidelidades[indiceFidelidade].pontos);
}

void consultarCartaoFidelidade(Fidelidade fidelidades[], int totalFidelidades)
{
    int idFidelidade;
    int indice = -1;
    int pontos;
    int proximoBeneficio = 0;

    printf("\n===== CONSULTAR CARTAO FIDELIDADE =====\n");
    printf("Digite o ID do cartao: ");

    if (scanf("%d", &idFidelidade) != 1) {
        printf("ID invalido.\n");
        return;
    }

    for (int i = 0; i < totalFidelidades; i++) {
        if (fidelidades[i].id_fidelidade == idFidelidade &&
            fidelidades[i].ativo == 1) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Cartao nao encontrado ou inativo.\n");
        return;
    }

    pontos = fidelidades[indice].pontos;

    printf("\nID do cartao: %d\n", fidelidades[indice].id_fidelidade);
    printf("ID do cliente: %d\n", fidelidades[indice].id_cliente);
    printf("Pontos atuais: %d\n", pontos);

    printf("\nBeneficios disponiveis:\n");
    if (pontos >= 100) {
        printf("- Beneficio de 100 pontos\n");
    }
    if (pontos >= 200) {
        printf("- Beneficio de 200 pontos\n");
    }
    if (pontos >= 500) {
        printf("- Beneficio de 500 pontos\n");
    }
    if (pontos < 100) {
        printf("Nenhum beneficio disponivel no momento.\n");
    }

    if (pontos < 100) {
        proximoBeneficio = 100;
    } else if (pontos < 200) {
        proximoBeneficio = 200;
    } else if (pontos < 500) {
        proximoBeneficio = 500;
    }

    if (proximoBeneficio > 0) {
        printf("Faltam %d pontos para o proximo beneficio (%d pontos).\n",
               proximoBeneficio - pontos, proximoBeneficio);
    } else {
        printf("Voce ja alcancou todos os beneficios disponiveis.\n");
    }
}

int buscarFidelidadePorIdCliente(Fidelidade fidelidades[],
                                 int totalFidelidades, int id_cliente)
{
    for (int i = 0; i < totalFidelidades; i++) {
        if (fidelidades[i].id_cliente == id_cliente &&
            fidelidades[i].ativo == 1) {
            return i;
        }
    }

    return -1;
}
