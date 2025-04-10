#include <stdio.h> 
#include <stdlib.h> 
#include "cardapio.c"

int main(){
    Cardapio* cardapio = criarCardapio(); //Já falo para criar a minha lista de cardápio
    int opcao; 
    char nome[50];
    float preco;

    do{
        printf("\n=== CAFETERIA ===\n");
        printf("1. Adicionar item ao cardapio\n");
        printf("2. Remover item do cardápio\n");
        printf("3. Listar itens do cardapio\n");
        printf("4. Buscar preço do item\n");
        printf("5. Fechar o sistema\n");
        printf("Escolha uma opção: \n");
      
      
        scanf("%d", &opcao);
        while (getchar() != '\n');  //Consumir '\n' pendente 

        switch (opcao){
            case 1:
            printf("Nome do item: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0'; //uso antes do printf senão da um \n aleatorio

            printf("Preço do item: ");
            scanf("%f", &preco);
            adicionarItem(cardapio, nome, preco);
            while (getchar() != '\n');  //Consumir '\n' pendente 

            break;

            case 2: 
            printf("Nome do item a remover\n");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            removerItem(cardapio, nome);
            break;

            case 3:
            listarCardapio(cardapio);
            break;

            case 4: 
            printf("Nome do item a buscar: \n");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            preco = buscarPreco(cardapio, nome);
            if(preco >= 0){
                printf("preço de '%s' : R$ %.2f\n", nome, preco);
            }
            else{
                    printf("item não encontrado!\n");
            }
            break;
            
            case 5:
        liberarCardapio(cardapio);
        printf("Encerrando o sitema...\n");
        break;

        default: 
        printf("Invalido\n");
        break;
        }

       
    }while (opcao != 5);

    return 0;

}