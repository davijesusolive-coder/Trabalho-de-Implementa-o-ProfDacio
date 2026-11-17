#include <stdio.h>
#include <string.h>
#include "beneficio.h"
#include "movimentacao.h" 

#define PONTOS_MINIMO_SORTEIO 500

typedef struct {
    int codigo;
    const char *descricao;
    int custo;          
} Beneficio;

static const Beneficio BENEFICIOS[] = {
    {1, "Desconto de 10%",       100},
    {2, "Brinde da loja",        250},
    {3, "Vale-compras R$ 50",    400},
    {4, "Vale-compras R$ 100",   750}
};
#define TOTAL_BENEFICIOS (int)(sizeof(BENEFICIOS) / sizeof(BENEFICIOS[0]))

static int buscarFidelidade(Fidelidade fidelidades[], int total, int id)
{
    for (int i = 0; i < total; i++) {
        if (fidelidades[i].id_fidelidade == id)
            return i;
    }
    return -1;
}

static const char *buscarNomeCliente(Cliente clientes[], int total, int id)
{
    for (int i = 0; i < total; i++) {
        if (clientes[i].id_cliente == id)
            return clientes[i].nome;
    }
    return "(cliente nao encontrado)";
}

void resgatarBeneficio(Fidelidade fidelidades[], int totalFidelidades,
                       Movimentacao movimentacoes[], int *totalMovimentacoes)
{
    int id, opcao;

    printf("\n=== Resgatar Beneficio ===\n");
    printf("Informe o ID de fidelidade: ");
    if (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("Entrada invalida.\n");
        return;
    }

    int pos = buscarFidelidade(fidelidades, totalFidelidades, id);
    if (pos == -1) {
        printf("ID de fidelidade nao encontrado.\n");
        return;
    }

    printf("Saldo atual: %d pontos\n\n", fidelidades[pos].pontos);
    printf("Beneficios disponiveis:\n");
    for (int i = 0; i < TOTAL_BENEFICIOS; i++) {
        printf("  %d - %-22s (%d pontos)\n",
               BENEFICIOS[i].codigo, BENEFICIOS[i].descricao, BENEFICIOS[i].custo);
    }

    printf("Escolha o beneficio (0 para cancelar): ");
    if (scanf("%d", &opcao) != 1) {
        while (getchar() != '\n');
        printf("Entrada invalida.\n");
        return;
    }
    if (opcao == 0) {
        printf("Operacao cancelada.\n");
        return;
    }

    const Beneficio *b = NULL;
    for (int i = 0; i < TOTAL_BENEFICIOS; i++) {
        if (BENEFICIOS[i].codigo == opcao) {
            b = &BENEFICIOS[i];
            break;
        }
    }
    if (b == NULL) {
        printf("Beneficio invalido.\n");
        return;
    }

    if (fidelidades[pos].pontos < b->custo) {
        printf("Pontos insuficientes. Faltam %d pontos.\n",
               b->custo - fidelidades[pos].pontos);
        return;
    }

    fidelidades[pos].pontos -= b->custo;
    registrarMovimentacao(movimentacoes, totalMovimentacoes,
                          id, "Debito", b->custo);

    printf("Beneficio \"%s\" resgatado com sucesso!\n", b->descricao);
    printf("Novo saldo: %d pontos\n", fidelidades[pos].pontos);
}

void consultarSorteio(Cliente clientes[], int totalClientes,
                      Fidelidade fidelidades[], int totalFidelidades)
{
    int participantes = 0;

    printf("\n=== Participantes do Sorteio (minimo %d pontos) ===\n",
           PONTOS_MINIMO_SORTEIO);

    for (int i = 0; i < totalFidelidades; i++) {
        if (fidelidades[i].pontos >= PONTOS_MINIMO_SORTEIO) {
            printf("- %s (ID cliente: %d, %d pontos)\n",
                   buscarNomeCliente(clientes, totalClientes, fidelidades[i].id_cliente),
                   fidelidades[i].id_cliente,
                   fidelidades[i].pontos);
            participantes++;
        }
    }

    if (participantes == 0)
        printf("Nenhum cliente atingiu a pontuacao minima.\n");
    else
        printf("Total de participantes: %d\n", participantes);
}
