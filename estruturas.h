// Estrutura para armazenamento dos Clientes
typedef struct {
    int id_cliente;
    char nome[100];
    char cpf[15];
    char telefone[20];
    char email[100];
    int ativo; // 1 para ativo, 0 para removido (exclusão lógica)
} Cliente;

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
