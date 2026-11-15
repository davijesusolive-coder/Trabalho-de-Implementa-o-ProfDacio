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
    Cliente novoCliente;

    if (*totalClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    getchar();

    printf("\n===== CADASTRO DE CLIENTE =====\n");

    printf("Nome: ");
    fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);
    novoCliente.nome[strcspn(novoCliente.nome, "\n")] = '\0';

    printf("CPF: ");
    fgets(novoCliente.cpf, sizeof(novoCliente.cpf), stdin);
    novoCliente.cpf[strcspn(novoCliente.cpf, "\n")] = '\0';

    printf("Telefone: ");
    fgets(novoCliente.telefone, sizeof(novoCliente.telefone), stdin);
    novoCliente.telefone[strcspn(novoCliente.telefone, "\n")] = '\0';

    printf("Email: ");
    fgets(novoCliente.email, sizeof(novoCliente.email), stdin);
    novoCliente.email[strcspn(novoCliente.email, "\n")] = '\0';

    int indice = buscarClientePorCpf(clientes, *totalClientes, novoCliente.cpf);

    if (indice != -1) {
        printf("Erro: este CPF ja esta cadastrado!\n");
        return;
    }

    novoCliente.id_cliente = *totalClientes + 1;
    novoCliente.ativo = 1;

    clientes[*totalClientes] = novoCliente;

    Fidelidade novoCartao;

    novoCartao.id_fidelidade = *totalFidelidades + 1;
    novoCartao.id_cliente = novoCliente.id_cliente;
    novoCartao.pontos = 0;
    novoCartao.nivel = 1;
    novoCartao.ativo = 1;

    fidelidades[*totalFidelidades] = novoCartao;

    (*totalClientes)++;
    (*totalFidelidades)++;

    printf("\nCliente cadastrado com sucesso!\n");
    printf("ID do cliente: %d\n", novoCliente.id_cliente);
    printf("ID do cartao: %d\n", novoCartao.id_fidelidade);
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

        if (strcmp(clientes[i].cpf, cpf) == 0) {
            return i;
        }

    }

    return -1;
}