#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 50

typedef struct {
    char titulo[100];
    char autor[100];
    int ano_publicacao;
    int exemplares_disponiveis;
} Livro;

void cadastrar_livros(Livro livros[], int *total);
void exibir_livros_por_autor(Livro livros[], int total, const char *autor);
void listar_livros_publicados_antes(Livro livros[], int total, int ano);
void cadastrar_livros(Livro livros[], int *total) {
    int quantidade;

    if (*total >= MAX_LIVROS) {
        printf("Limite maximo de livros atingido!\n");
        return;
    }

    printf("Quantos livros deseja cadastrar? (Disponivel: %d): ", MAX_LIVROS - *total);
    scanf("%d", &quantidade);
    getchar();

    if (*total + quantidade > MAX_LIVROS) {
        printf("Erro: Voce pode cadastrar no maximo %d livros.\n", MAX_LIVROS - *total);
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Cadastro do livro %d ---\n", *total + 1);

        printf("Titulo: ");
        fgets(livros[*total].titulo, sizeof(livros[*total].titulo), stdin);
        livros[*total].titulo[strcspn(livros[*total].titulo, "\n")] = '\0';

        printf("Autor: ");
        fgets(livros[*total].autor, sizeof(livros[*total].autor), stdin);
        livros[*total].autor[strcspn(livros[*total].autor, "\n")] = '\0';

        printf("Ano de publicacao: ");
        scanf("%d", &livros[*total].ano_publicacao);
        getchar();

        printf("Numero de exemplares disponiveis: ");
        scanf("%d", &livros[*total].exemplares_disponiveis);
        getchar();

        (*total)++;
    }

    printf("Livros cadastrados com sucesso!\n");
}

void exibir_livros_por_autor(Livro livros[], int total, const char *autor) {
    if (total == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    int encontrados = 0;
    printf("\nLivros do autor '%s':\n", autor);
    for (int i = 0; i < total; i++) {
        if (strcmp(livros[i].autor, autor) == 0) {
            printf("Titulo: %s | Ano: %d | Exemplares Disponiveis: %d\n",
                   livros[i].titulo, livros[i].ano_publicacao, livros[i].exemplares_disponiveis);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum livro encontrado do autor '%s'.\n", autor);
    }
}

void listar_livros_publicados_antes(Livro livros[], int total, int ano) {
    if (total == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    int encontrados = 0;
    printf("\nLivros publicados antes de %d:\n", ano);
    for (int i = 0; i < total; i++) {
        if (livros[i].ano_publicacao < ano) {
            printf("Titulo: %s | Autor: %s | Ano: %d | Exemplares Disponiveis: %d\n",
                   livros[i].titulo, livros[i].autor, livros[i].ano_publicacao, livros[i].exemplares_disponiveis);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum livro encontrado publicado antes de %d.\n", ano);
    }
}


int main() {
    Livro livros[MAX_LIVROS];
    int total_livros = 0;
    int opcao;

    do {
    printf("\n=== Sistema de gerenciamento de livros da biblioteca ===\n");
    printf("1. Cadastrar livros\n");
    printf("2. Exibir livros de um autor especifico\n");
    printf("3. listar livros publicados antes de um ano especificado\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    switch (opcao) {
    case 1:
            cadastrar_livros(livros, &total_livros);
            break;
        case 2: {
                char autor[100];
                printf("Informe o nome do autor: ");
                fgets(autor, sizeof(autor), stdin);
                autor[strcspn(autor, "\n")] = '\0';
                exibir_livros_por_autor(livros, total_livros, autor);
                break;
            }
        case 3: {
                int ano;
                printf("Informe o ano: ");
                scanf("%d", &ano);
                listar_livros_publicados_antes(livros, total_livros, ano);
                break;
            }
        case 4:
            printf("Saindo...\n");
                break;
        default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}