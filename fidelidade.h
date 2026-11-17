#ifndef FIDELIDADE_H
#define FIDELIDADE_H

#include "estruturas.h"

// Modulo responsavel por: Registrar Compra (opcao 2) e Consultar Cartao
// Fidelidade (opcao 3)
// Responsavel: Pessoa 2

void registrarCompra(Cliente clientes[], int totalClientes, Fidelidade fidelidades[], int totalFidelidades, Movimentacao movimentacoes[], int *totalMovimentacoes) {
  printf("\n===== REGISTRAR COMPRA =====\n");
  printf("ID do Cliente: ");
  if(scanf("%d", %Cliente.id_cliente) != 1){
    while(getchar() != '\n');
    printf("Entrada Invalida!\n");
    return;
  }
  if(Cliente.ativo == 0) {
    printf("Cliente não encontrado!");
    return;
  }
  
  printf("%d", Cliente.id_cliente)

}

void consultarCartaoFidelidade(Fidelidade fidelidades[], int totalFidelidades);

// Helper publico: beneficio.c tambem vai precisar localizar o cartao de
// fidelidade de um cliente pra checar/descontar pontos.
int buscarFidelidadePorIdCliente(Fidelidade fidelidades[], int totalFidelidades, int id_cliente);

#endif
