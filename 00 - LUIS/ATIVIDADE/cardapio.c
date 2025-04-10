#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "cardapio.h"

// Definição real da estrutura (oculta para quem usa o .h)
struct Item{
    int id;
    char nome[50];
    float preco;
    struct Item* prox; //Vou usar para ir para o próximo laço
};

struct Cardapio{
    struct Item* inicio;   //Parece que eu uso essa struct para ligar com a outra 
};

//criar um cardápio vazio 
Cardapio* criarCardapio(){
    Cardapio* cardapio = (Cardapio*)malloc(sizeof(Cardapio));
    if(!cardapio){
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    cardapio->inicio = NULL;
    return cardapio;
}

//Adicionar um item ao cardapio 
void adicionarItem(Cardapio* cardapio, int id, char nome[], float preco){ //é  melhor pegar os valores de fora e inserir na struct do que pegar eles para a struct
    struct Item* novo = (struct Item*)malloc(sizeof(struct Item));
    if(!novo){
        printf("Erro ao alocar memória\n");
        return;
    }
    novo-> id = id;
    strcpy(novo->nome, nome);
    novo->preco = preco;
    novo->prox = cardapio->inicio;
    cardapio->inicio = novo;
    printf("Item '%s' adicionado ao cardápio!\n", nome);
}

// remover um item do cardapio 
void removerItem(Cardapio* cardapio, char nome[]){
    struct Item *atual = cardapio->inicio, *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0){
        atual = anterior;
        atual = atual->prox;
    }
    if(!atual){
        printf("item '%s' não encontrado!\n", nome);
        return;
    }

    if(!anterior) {
        cardapio->inicio = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("item '%s' removido do cardapio\n", nome);
}
 
//    listar todos os itens do cardapio 
void listarCardapio(Cardapio* cardapio){
    struct Item* atual = cardapio->inicio;
    if(!atual){
        printf("O cardapio está vazio!\n");
        return;
    }

    printf("\n === Cardapio da Cafeteria ===\n");
    while(atual){
        printf("- %s | R$ %.2f\n", atual->nome, atual->preco);
        atual = atual->prox;
    }
    printf("==================================\n");
}


// buscar proço de um  item 
float cardapio_obter_preco(Cardapio* cardapio, int id) {
    struct Item* atual = cardapio->inicio;
    while (atual) {
        if (atual->id == id) {
            return atual->preco;
        }
        atual = atual->prox;
    }
    return -1; // Item não encontrado
}

char* cardapio_obter_nome(Cardapio* cardapio, int id) {
    struct Item* atual = cardapio->inicio;
    while (atual) {
        if (atual->id == id) return atual->nome;
        atual = atual->prox;
    }
    return NULL;
}

void liberarCardapio(Cardapio* cardapio){
    struct Item* atual = cardapio->inicio;

    while(atual){
        struct Item* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(cardapio);
