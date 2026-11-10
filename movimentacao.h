#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include "estruturas.h"

// Modulo responsavel por: registrar e consultar o historico de
// movimentacoes de pontos (usado internamente por fidelidade.c e
// beneficio.c)
// Responsavel: Pessoa 4 (junto com main.c)

void registrarMovimentacao(Movimentacao movimentacoes[], int *totalMovimentacoes,
                            int id_cliente, int pontos, const char *tipo, const char *data);

void listarMovimentacoes(Movimentacao movimentacoes[], int totalMovimentacoes);

#endif
