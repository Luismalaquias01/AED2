#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 20

// Estrutura para armazenar informações de um produto
struct Produto {
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
};

// Protótipos das funções
void cadastrar_produtos(struct Produto produtos[], int *total);
void atualizar_estoque(struct Produto produtos[], int total);
void exibir_mais_caro_e_mais_barato(struct Produto produtos[], int total);
void exibir_produto(struct Produto produto);

int main() {
    struct Produto produtos[MAX_PRODUTOS];
    int total_produtos = 0, opcao;

    do {
        printf("\n=== Sistema de Controle de Estoque ===\n");
        printf("1. Cadastrar Produtos\n");
        printf("2. Atualizar Quantidade em Estoque\n");
        printf("3. Exibir Produto Mais Caro e Mais Barato\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer

        switch (opcao) {
            case 1:
                cadastrar_produtos(produtos, &total_produtos);
                break;
            case 2:
                atualizar_estoque(produtos, total_produtos);
                break;
            case 3:
                exibir_mais_caro_e_mais_barato(produtos, total_produtos);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

// Função para cadastrar produtos
void cadastrar_produtos(struct Produto produtos[], int *total) {
    int quantidade;

    if (*total >= MAX_PRODUTOS) {
        printf("Limite maximo de produtos atingido!\n");
        return;
    }

    printf("Quantos produtos deseja cadastrar? (Maximo disponivel: %d): ", MAX_PRODUTOS - *total);
    scanf("%d", &quantidade);
    getchar();

    if (*total + quantidade > MAX_PRODUTOS) {
        printf("Voce so pode cadastrar ate %d produtos.\n", MAX_PRODUTOS - *total);
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Cadastro do Produto %d ---\n", *total + 1);
        printf("Nome: ");
        fgets(produtos[*total].nome, sizeof(produtos[*total].nome), stdin);
        produtos[*total].nome[strcspn(produtos[*total].nome, "\n")] = '\0';

        printf("Codigo do Produto: ");
        scanf("%d", &produtos[*total].codigo);
        getchar();

        printf("Preco: ");
        scanf("%f", &produtos[*total].preco);
        getchar();

        printf("Quantidade em Estoque: ");
        scanf("%d", &produtos[*total].quantidade);
        getchar();

        (*total)++;
    }

    printf("Produtos cadastrados com sucesso!\n");
}

// Função para atualizar a quantidade em estoque
void atualizar_estoque(struct Produto produtos[], int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado ainda.\n");
        return;
    }

    int codigo, nova_quantidade;
    printf("Digite o codigo do produto para atualizar: ");
    scanf("%d", &codigo);
    getchar();

    int encontrado = 0;
    for (int i = 0; i < total; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Produto encontrado: %s | Estoque atual: %d\n", produtos[i].nome, produtos[i].quantidade);
            printf("Digite a nova quantidade em estoque: ");
            scanf("%d", &nova_quantidade);
            produtos[i].quantidade = nova_quantidade;
            printf("Quantidade atualizada com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto com codigo %d nao encontrado.\n", codigo);
    }
}

// Função para exibir o produto mais caro e mais barato
void exibir_mais_caro_e_mais_barato(struct Produto produtos[], int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    struct Produto mais_caro = produtos[0];
    struct Produto mais_barato = produtos[0];

    for (int i = 1; i < total; i++) {
        if (produtos[i].preco > mais_caro.preco) {
            mais_caro = produtos[i];
        }
        if (produtos[i].preco < mais_barato.preco) {
            mais_barato = produtos[i];
        }
    }

    printf("\n--- Produto Mais Caro ---\n");
    exibir_produto(mais_caro);

    printf("\n--- Produto Mais Barato ---\n");
    exibir_produto(mais_barato);
}

// Função auxiliar para exibir informações de um produto
void exibir_produto(struct Produto produto) {
    printf("Nome: %s\n", produto.nome);
    printf("Codigo: %d\n", produto.codigo);
    printf("Preco: %.2f\n", produto.preco);
    printf("Quantidade em Estoque: %d\n", produto.quantidade);
}
