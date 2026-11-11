#include <stdio.h>
#include <string.h>
#include "estruturas.h"
#include "menu.h"

int main(){
    int opcao;
    int quantidadeClientes = 0;
    Cliente clientes[100]; // Array para armazenar até 100 clientes


    do{
        
        opcao = exibir_menu();

        switch (opcao){
            case 1:
                // Chamaa a função de cadastro de cliente
                if (quantidadeClientes < 100) //Antes de cadastrar, verifica se ainda há espaço para um novo cadastro (limite de 100)
                {

                    clientes[quantidadeClientes].id_cliente = quantidadeClientes + 1; //Clientes: nosso vetor. [quantidadeClientes] = posição do cliente no vetor.
                    //id_cliente = quantidadeClientes + 1 (para que o ID comece em 1 e não em 0)
                    //Podemos imaginar assim:
                    //Primeiro cadastro: clientes[0].id_cliente = 0 + 1;
                    //Segundo cadastro: clientes[1].id_cliente = 1 + 1;
                    //Terceiro cadastro: clientes[2].id_cliente = 2 + 1;
                    //E assim por diante até chegar em 100
                    clientes[quantidadeClientes].ativo = 1; //1 para ativo, 0 para removido (exclusão lógica). Afirmando que o cliente está ativo no sistema.

                    getchar(); //Essa linha existe por causa de um pequeno detalhe do funcionamento do teclado.
                    //Quando o usuário digita uma opção no menu, por exemplo 1, e aperta ENTER, 
                    //o programa recebe o número, mas o ENTER pode continuar aguardando na fila de entrada. 
                    //Então, quando o programa chega na função fgets, ele lê esse ENTER e não espera o usuário digitar o nome do cliente. 
                    //Para evitar isso, usamos a função getchar() para "limpar" o buffer de entrada antes de chamar fgets.

                    printf("\nDigite seu nome: ");
                    fgets(clientes[quantidadeClientes].nome, 100, stdin); //Usamos fgets para ler o nome do cliente, permitindo que ele contenha espaços.

                    clientes[quantidadeClientes].nome[strcspn(clientes[quantidadeClientes].nome, "\n")] = '\0';//Aqui ocorre a leitura ;-;
                    //clientes[quantidadeClientes].nome: Onde o texto será armazenado.
                    //100 limite de caracteres que podem ser lidos.
                    //stdin: Indica que a entrada será feita pelo teclado.

                    //Quando usamos fgets, o ENTER pressionado também pode ser armazenado no final do texto.
                    //Para evitar que o ENTER seja armazenado, usamos a função strcspn para encontrar a posição do '\n' (ENTER) e substituí-lo por '\0' (fim da string).
                    //Por exemplo, o nome pode ficar assim:
                    //Antes: "Pedro Henrique\n"
                    //Depois: "Pedro Henrique"

                    quantidadeClientes++; //Aumenta o valor da variável (no vaso o número de clientes cadastrados) em 1.

                    printf("\nCadastrado com sucesso!");
                }
                else{
                    printf("\nLimite de cadastros atingido."); //Mensagem caso o limite de cadastros tenha sido atingida
                }
                break;
            
            case 2:
                // Chama a função de registrar compra
                printf("Registrar Compra selecionado.\n");
                break;
            case 3:
                // Chama a função de consultar cartão fidelidade
                printf("Consultar Cartao Fidelidade selecionado.\n");
                break;
            case 4:
                // Chama a função de resgatar benefício
                printf("Resgatar Beneficio selecionado.\n");
                break;
            case 5:
                // Chama a função de consultar sorteio
                printf("Consultar Sorteio selecionado.\n");
                break;
            case 6:
                // Chama a função de listar clientes
                printf("===== CLIENTES CADASTRADOS =====\n");
                for (int i =0; i < quantidadeClientes; i++){ //Essa linha cria um loop que percorre todos os clientes cadastrados.
                    if (clientes[i].ativo ==1){ //Essa linha verifica se o cliente está ativo (ativo == 1). Se estiver, ele será listado. Caso não ele será pulado e ir ao próximo.
                        printf("ID: %d | Nome: %s\n", clientes[i].id_cliente, clientes[i].nome); //Essa linha imprime o ID e em seguida o nome do cliente.
                        //No fim, ficaria assim:
                        //ID: 1 | Nome: Pedro Henrique
                        //ID: 2 | Nome: Davi Jesus
                    }
                }
                break;
            case 0:
                printf("Encerrando programa.\n");
                return 0;
                
            case -1:
                printf("\nEntrada invalida!\n");
                break;
                
            default:
                printf("Opcao invalida.\n");
        }
    }while (opcao != 0);
    
    return 0;
}
