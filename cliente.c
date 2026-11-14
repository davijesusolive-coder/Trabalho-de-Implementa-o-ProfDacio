#include <stdio.h>
#include <string.h>
#include "cliente.h"

/*
 * TODO (Pessoa 1): implementar o cadastro de verdade.
 * Deve: pedir nome, cpf, telefone, email; usar buscarClientePorCpf pra
 * verificar se o cpf ja existe; se NAO existir, adicionar em clientes[]
 * (incrementando *totalClientes) e criar o cartao de fidelidade
 * correspondente em fidelidades[] (incrementando *totalFidelidades).
 */
void cadastrarCliente(Cliente clientes[], int *totalClientes, Fidelidade fidelidades[], int *totalFidelidades)
{
    printf("[cadastrarCliente] ainda nao implementado.\n");
}

/*
 * TODO (Pessoa 1): implementar a listagem de verdade.
 * Deve: percorrer clientes[] e imprimir os que estiverem com ativo == 1.
 */
void listarClientes(Cliente clientes[], int totalClientes)
{
    printf("\n===== CLIENTES CADASTRADOS =====\n");

    if (totalClientes == 0) {
    printf("Nenhum cliente cadastrado.\n");
    return;
}

    for (int i = 0; i < totalClientes; i++) {

        if (clientes[i].ativo == 1) {

            printf("\nID: %d\n", clientes[i].id_cliente);
            printf("Nome: %s\n", clientes[i].nome);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("Email: %s\n", clientes[i].email);

        }
    }
}

/*
 * TODO (Pessoa 1): implementar a busca de verdade.
 * Deve: percorrer clientes[] comparando o cpf (strcmp) e devolver o
 * indice encontrado, ou -1 se nao achar.
 */
int buscarClientePorCpf(Cliente clientes[], int totalClientes, const char *cpf)
{
    for (int i = 0; i < totalClientes; i++) {

        if (strcmp(clientes[i].cpf, cpf) == 0 && clientes[i].ativo == 1) {
            return i;
        }

    }
    return -1;
}