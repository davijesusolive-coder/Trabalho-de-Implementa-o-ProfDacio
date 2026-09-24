# Sistema de Cadastro de Clientes + Sistema de fidelidade de Clientes

## 1. Descrição:

- ___*Sistema voltado a cadastro de clientes frequentes e a cada compra do cliente ele ganha uma marcação no seu cartão fidelidade, a cada X marcações no cartão fidelidade o cliente ganha um brinde da loja ou um X% de desconto na loja e também com X marcações no cartão fidelidade o cliente está sujeito a participar de um sorteio da loja.*___

## 2. Fluxo de Utilização Esperado para o Sistema:

*1. Ao iniciar o programa, o usuário visualizará um menu principal com as opções:*

    1. Cadastrar Cliente
    2. Registrar Compra
    3. Consultar Cartão Fidelidade
    4. Resgatar Benefício
    5. Consultar Sorteio
    6. Listar Clientes
    7. Sair
2. *Caso o usuário escolha **1. Cadastrar Cliente**, o sistema solicitará os dados necessários. O sistema verificará se o cliente já está cadastrado e, caso não esteja, armazenará seus dados juntamente com seu cartão fidelidade.*

3. *Se o usuário escolher **2. Registrar Compra**, o sistema solicitará o CPF ou código do cliente. Após localizar o cadastro, o sistema registrará a compra e adicionará uma marcação ao cartão fidelidade do cliente.*

4. *Ao selecionar **3. Consultar Cartão Fidelidade**, o sistema solicitará o identificador(id_fidelidade) do cliente e exibirá informações como quantidade atual de marcações, quantidade necessária para o próximo benefício e benefícios disponíveis para resgate.*

5. *Se o usuário escolher **4. Resgatar Benefício**, o sistema verificará se o cliente possui marcações suficientes para utilizar o benefício. Em caso positivo, o benefício será registrado como utilizado e a quantidade de marcações será atualizada conforme as regras definidas pela loja.*

6. *Ao escolher **5. Consultar Sorteio**, o sistema verificará quais clientes possuem a quantidade mínima de marcações necessária para participar do sorteio.*

7. *Ao selecionar **7. Sair**, o sistema encerrará sua execução, mantendo os cadastros, compras, marcações e informações dos benefícios armazenados para utilização posterior.*

8. *Em todas as operações, caso o cliente não esteja cadastrado, o sistema exibirá uma mensagem de erro clara e retornará ao menu principal e abrirá a tela de login. Caso seja apenas a falta de pontos irá apresentar apeans a mensagem clara de erro e redirecionar o usuário para o menu principal.*

## 3. Fluxograma da Lógica do Sistema:

<img width="942" height="1024" alt="image" src="https://github.com/user-attachments/assets/ed888d7f-63e6-4a43-8ba8-56afc5c3446a" />

## 4. Estrutura de Dados:

```c
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
