# Divisão de Módulos — Sistema de Fidelidade

Documento combinado pelo grupo na Semana 1, antes de começar a implementação.

## Estrutura de arquivos

```
fidelidade-cliente/
├── main.c              (menu principal + dados compartilhados)
├── estruturas.h        (Cliente, Fidelidade, Movimentacao — compartilhado por todos)
├── cliente.h / .c       → Pessoa 1
├── fidelidade.h / .c     → Pessoa 2
├── beneficio.h / .c      → Pessoa 3
└── movimentacao.h / .c   → Pessoa 4 (junto com main.c)
```

## Quem faz o quê

| Pessoa | Arquivos | Opções do menu | Funções |
|---|---|---|---|
| **1** | `cliente.h` / `cliente.c` | 1. Cadastrar Cliente, 6. Listar Clientes | `cadastrarCliente`, `listarClientes`, `buscarClientePorCpf` |
| **2** | `fidelidade.h` / `fidelidade.c` | 2. Registrar Compra, 3. Consultar Cartão Fidelidade | `registrarCompra`, `consultarCartaoFidelidade`, `buscarFidelidadePorIdCliente` |
| **3** | `beneficio.h` / `beneficio.c` | 4. Resgatar Benefício, 5. Consultar Sorteio | `resgatarBeneficio`, `consultarSorteio` |
| **4** | `movimentacao.h` / `movimentacao.c` + `main.c` | 7. Sair / menu principal | `registrarMovimentacao`, `listarMovimentacoes` |

## Como os módulos se conectam

- **`main.c` é o "dono" dos dados**: os arrays `clientes[]`, `fidelidades[]` e `movimentacoes[]` (e seus contadores) são criados lá e passados por parâmetro pra cada função — nenhum módulo tem variável global própria.
- **`fidelidade.c` depende de `cliente.c`**: usa `buscarClientePorCpf` pra achar o cliente antes de mexer no cartão dele (por isso `fidelidade.c` já inclui `cliente.h`).
- **`fidelidade.c` e `beneficio.c` vão depender de `movimentacao.c`**: toda vez que pontos mudam (compra = crédito, resgate = débito), devem chamar `registrarMovimentacao` pra manter o histórico.
- **`beneficio.c` depende de `cliente.c` e `fidelidade.c`**: pra listar o sorteio, precisa cruzar quem tem pontos suficientes (`fidelidades[]`) com o nome do cliente (`clientes[]`).

## Status atual (fim da Semana 1)

- [x] Estrutura de dados definida em `estruturas.h`
- [x] `main.c` criado com o menu completo, chamando todos os módulos
- [x] Esqueleto (assinatura + stub) de todas as funções, cada uma no arquivo do responsável
- [x] Projeto compila sem erros e roda o menu de ponta a ponta
- [ ] Lógica real de cada função (próximas semanas, um módulo por pessoa)

## Próximos passos (Semana 2 em diante)

Cada pessoa implementa a lógica real das próprias funções (removendo o `printf("... ainda nao implementado")` e substituindo pela implementação de verdade), fazendo commits frequentes no próprio módulo.
