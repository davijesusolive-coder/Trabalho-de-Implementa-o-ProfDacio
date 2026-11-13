#ifndef CLIENTE_H
#define CLIENTE_H

#include "estruturas.h"

// Modulo responsavel por: Cadastrar Cliente (opcao 1) e Listar Clientes (opcao 6)
// Responsavel: Pessoa 1

void cadastrarCliente(Cliente clientes[], int *totalClientes, Fidelidade fidelidades[], int *totalFidelidades);
void listarClientes(Cliente clientes[], int totalClientes);

// Helper publico: outros modulos (fidelidade.c, por exemplo) usam essa
// funcao para localizar um cliente pelo CPF antes de mexer no cartao dele.
// Retorna o INDICE do cliente em clientes[], ou -1 se nao encontrar.
int buscarClientePorCpf(Cliente clientes[], int totalClientes, const char *cpf);

#endif
