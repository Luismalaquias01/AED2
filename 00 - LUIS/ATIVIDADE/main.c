#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cardapio.h"

int main() {
    Cardapio* cardapio = criarCardapio();
    int opcao, id;
    char nome[50];
    float preco;

    do {
        printf("\n=== CAFETERIA ===\n");
        printf("1. Adicionar item ao cardápio\n");
        printf("2. Remover item do cardápio\n");
        printf("3. Listar itens do cardápio\n");
        printf("4. Buscar preço do item\n");
        printf("5. Fechar o sistema\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Consome o '\n'

        switch (opcao) {
            case 1:
                printf("ID do item: ");
                scanf("%d", &id);
                getchar(); // Limpa buffer

                printf("Nome do item: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Preço do item: ");
                scanf("%f", &preco);
                getchar(); // Limpa buffer

                adicionarItem(cardapio, id, nome, preco);
                break;

            case 2:
                printf("Nome do item a remover: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                removerItem(cardapio, nome);
                break;

            case 3:
                listarCardapio(cardapio);
                break;

                case 4:
                printf("ID do item a buscar: ");
                scanf("%d", &id);
                getchar(); // limpa o \n do buffer
            
                char* nome_item = cardapio_obter_nome(cardapio, id);
                float preco = cardapio_obter_preco(cardapio, id);
            
                if (nome_item && preco >= 0) {
                    printf("Preço de '%s': R$ %.2f\n", nome_item, preco);
                } else {
                    printf("Item não encontrado!\n");
                }
                break;
            
            case 5:
                cardapio_destruir(cardapio);
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 5);

    return 0;
}
