#include <stdio.h>
#include <stdlib.h>
#define TAM 50
#include <string.h>

void testeSwitch(){
    printf("Ok\n");
}

typedef struct {
    int id;
    char titulo[TAM];
    char autor[TAM];
    int anoPublicado;
    int qtdExemplares;
} Livro;

void cadastrarLivro(Livro *livros, int totalLivros){
    
    getchar();
    printf("Digite o titulo do livro: \n");

    fgets(livros[totalLivros].titulo, TAM, stdin);
    livros[totalLivros].titulo[strcspn(livros[totalLivros].titulo, "\n")] = '\0';

    printf("Digite o nome do autor: \n");

    fgets(livros[totalLivros].autor, TAM, stdin);
    livros[totalLivros].autor[strcspn(livros[totalLivros].autor, "\n")] = '\0';

    printf("Digite o ano de publicação: \n");
    scanf("%d", &livros[totalLivros].anoPublicado);

    printf("Digite quantidade de exemplares: \n");
    scanf("%d", &livros[totalLivros].qtdExemplares); 
    
    printf("Digite uma identificação numeral para o livro: ");
    scanf("%d", &livros[totalLivros].id); 

    printf("Livro cadastrado com sucesso!\n");
}

void listarLivros(Livro *livros, int totalLivros){

    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado ainda.\n");
        return;
    }
    
    for(int i = 0; i < totalLivros; i++){
        printf("\n===============================\n");
        printf("Livro %d\n", i+1);
        printf("Titulo:\n \t%s\n", livros[i].titulo);
        printf("Autor:\n \t%s\n", livros[i].autor);
        printf("Ano de publicação:\n \t%d\n", livros[i].anoPublicado);
        printf("Quantidade de exemplares:\n \t%d\n", livros[i].qtdExemplares);
        printf("Identificação:\n \t%d\n", livros[i].id);

    }
        printf("===============================\n");
}

Livro* buscarLivroPorTitulo(Livro *livros, int totalLivros, char buscado[]){
    for(int i = 0; i < totalLivros; i++){
        if (strcmp(buscado, livros[i].titulo) == 0) {
            return &livros[i]; 
        }
    }
    return NULL;
}

void atualizarExemplares(Livro *livro) {
    if (livro == NULL) {
        printf("Livro inválido.\n");
        return;
    }

    int novaQuantidade;
    printf("Quantidade atual: %d\n", livro->qtdExemplares);
    printf("Digite a nova quantidade de exemplares: ");
    scanf("%d", &novaQuantidade);

    livro->qtdExemplares = novaQuantidade;
    printf("Exemplares atualizados com sucesso!\n");
}

int main(){
    printf("Menu interativo ao Gerenciamento de Biblioteca");
    printf("\n\t==== Seja bem vindo! ====\n");
    int op;
    int quantidade = 0;
    Livro *acervo = NULL;

    do
    {
        printf("Escolha a sua ação desejada:\n");
        printf("[1]\tCadastra um novo livro.\n");
        printf("[2]\tLivros cadastrados.\n");
        printf("[3]\tBuscar um livro.\n");
        printf("[4]\tAtualizar exemplares.\n");
        printf("[5]\tSair.\n");

        scanf("%d", &op);

        switch (op)
        {
        case 1: {
            int qtd;
            printf("Quantos livros deseja cadastrar? ");
            scanf("%d", &qtd);

            Livro *novo = realloc(acervo, (quantidade + qtd) * sizeof(Livro));

            if (novo == NULL) {
                printf("Erro ao alocar memória.\n");
                free(acervo);
                return 1;
            }

            acervo = novo;

            if(acervo == NULL){
                printf("Erro ao alocar memória");
                exit(1);
            }

            for(int i = 0; i < qtd; i++){
                printf("\n Livro %d/%d\n", i+1, qtd);
                cadastrarLivro(novo, quantidade + i);
            }

            quantidade += qtd;    
            break;

        }
        case 2: {
            listarLivros(acervo, quantidade);
            break;

        }
        case 3: {
            char busca[TAM];
            getchar(); // limpa buffer
            printf("Qual livro deseja buscar?\n");
            fgets(busca, TAM, stdin);
            busca[strcspn(busca, "\n")] = '\0'; // remove \n
            Livro *resultado = buscarLivroPorTitulo(acervo, quantidade, busca);

            if(resultado!=NULL){
                printf("Livro encontrado:\n");
                printf("Título: %s\n", resultado->titulo);
                printf("Autor: %s\n", resultado->autor);
                printf("Ano: %d\n", resultado->anoPublicado);
                printf("Exemplares: %d\n", resultado->qtdExemplares);
                printf("ID: %d\n", resultado->id);
            }

            else{ 
                printf("Não encontrado!");
            }
            break;

        }
        case 4: {
            char tituloBusca[TAM];
            getchar(); // limpa buffer do scanf anterior

            printf("Digite o título do livro que deseja atualizar: ");
            fgets(tituloBusca, TAM, stdin);
            tituloBusca[strcspn(tituloBusca, "\n")] = '\0'; // remove o \n

            Livro *livro = buscarLivroPorTitulo(acervo, quantidade, tituloBusca);

            if (livro != NULL) {
            atualizarExemplares(livro);
            } else {
            printf("Livro não encontrado.\n");
            }
            break;

        }
        case 5: {
            printf("Adeus\n");
            break;
        }

        default:
            printf("Inválido, digite novamente.");
            break;
        }

    } while (op != 5);

    return 0;
}