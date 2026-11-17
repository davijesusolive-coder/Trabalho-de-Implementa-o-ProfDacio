#include <stdio.h>
#include "beneficio.h"

/*
 * TODO (Pessoa 3): implementar de verdade.
 * Deve: pedir id_fidelidade, verificar se tem pontos suficientes pro
 * beneficio desejado; se sim, descontar os pontos conforme a regra da
 * loja e chamar registrarMovimentacao (de movimentacao.c) com tipo
 * "Debito".
 */
void resgatarBeneficio(Fidelidade fidelidades[], int totalFidelidades,
                        Movimentacao movimentacoes[], int *totalMovimentacoes)
{
    printf("[resgatarBeneficio] ainda nao implementado.\n");
}

/*
 * TODO (Pessoa 3): implementar de verdade.
 * Deve: percorrer fidelidades[], e para cada uma com pontos >= minimo
 * definido pela loja, imprimir o cliente correspondente (buscando o
 * nome em clientes[] pelo id_cliente) como participante do sorteio.
 */
void consultarSorteio(Cliente clientes[], int totalClientes,
                       Fidelidade fidelidades[], int totalFidelidades)
{
    printf("[consultarSorteio] ainda nao implementado.\n");
}
