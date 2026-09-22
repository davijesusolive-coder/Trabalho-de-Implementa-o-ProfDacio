# Sistema de Cadastro de Clientes + Sistema de fidelidade de Clientes

## 1. Descrição:

- Sistema voltado a cadastro de clientes frequentes e a cada compra do cliente ele ganha uma marcação no seu cartão fidelidade, a cada X marcações no cartão fidelidade o cliente ganha um brinde da loja ou um X% de desconto na loja e também com X marcações no cartão fidelidade o cliente está sujeito a participar de um sorteio da loja.


## 4.Estrutura de Dados:

´´´´c
// Estrutura para armazenamento dos Clientes
typedef struct {
    int id_cliente;
    char nome[100];
    char cpf[15];
    char telefone[20];
    char email[100];
    int ativo; // 1 para ativo, 0 para removido (exclusão lógica)
} Cliente;


// Estrutura para armazenamento dos dados de Fidelidade
typedef struct {
    int id_fidelidade;
    int id_cliente;
    int pontos;
    int nivel; // 1 = Bronze, 2 = Prata, 3 = Ouro
    int ativo; // 1 para ativo, 0 para inativo
} Fidelidade;


// Estrutura para registro das movimentações de pontos
typedef struct {
    int id_movimentacao;
    int id_cliente;
    int pontos;
    char tipo[20]; // "Credito" ou "Debito"
    char data[11]; // formato DD/MM/AAAA
} Movimentacao;
