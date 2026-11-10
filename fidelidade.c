#include <stdio.h>
#include "fidelidade.h"
#include "cliente.h" // para usar buscarClientePorCpf

/*
 * TODO (Pessoa 2): implementar de verdade.
 * Deve: pedir o cpf (ou codigo) do cliente, usar buscarClientePorCpf
 * (de cliente.c) pra localizar; se encontrar, usar
 * buscarFidelidadePorIdCliente pra achar o cartao, aumentar os pontos,
 * e chamar registrarMovimentacao (de movimentacao.c) com tipo "Credito".
 */
void registrarCompra(Cliente clientes[], int totalClientes,
                      Fidelidade fidelidades[], int totalFidelidades,
                      Movimentacao movimentacoes[], int *totalMovimentacoes)
{
    printf("[registrarCompra] ainda nao implementado.\n");
}

/*
 * TODO (Pessoa 2): implementar de verdade.
 * Deve: pedir o id_fidelidade, exibir pontos atuais, quanto falta pro
 * proximo beneficio, e quais beneficios ja estao disponiveis pra resgate.
 */
void consultarCartaoFidelidade(Fidelidade fidelidades[], int totalFidelidades)
{
    printf("[consultarCartaoFidelidade] ainda nao implementado.\n");
}

/*
 * TODO (Pessoa 2): implementar de verdade.
 * Deve: percorrer fidelidades[] procurando o registro cujo id_cliente
 * bate com o parametro, devolvendo o indice ou -1 se nao achar.
 */
int buscarFidelidadePorIdCliente(Fidelidade fidelidades[], int totalFidelidades, int id_cliente)
{
    printf("[buscarFidelidadePorIdCliente] ainda nao implementado.\n");
    return -1;
}
