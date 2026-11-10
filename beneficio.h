#ifndef BENEFICIO_H
#define BENEFICIO_H

#include "estruturas.h"

// Modulo responsavel por: Resgatar Beneficio (opcao 4) e Consultar
// Sorteio (opcao 5)
// Responsavel: Pessoa 3

void resgatarBeneficio(Fidelidade fidelidades[], int totalFidelidades,
                        Movimentacao movimentacoes[], int *totalMovimentacoes);

void consultarSorteio(Cliente clientes[], int totalClientes,
                       Fidelidade fidelidades[], int totalFidelidades);

#endif
