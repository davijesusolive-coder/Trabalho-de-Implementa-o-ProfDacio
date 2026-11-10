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

typedef struct {
    int id_do_produto;
    char nome_do_produto[200];
    int quantidade_em_estoque;
    double preco;
    char descricao[500];
    int ativo; // 1 para produtos validos ou em estoque, 0 para produtos invalidos ou com falta no estoque 
} Registro_de_Produto;
