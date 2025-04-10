#include <stdio.h>
#include "Lista.h"
#include <stdlib.h>
// Definição da struct (visível apenas no .c)
struct ElementoLista {
    int valor;
    struct ElementoLista *prox;
};

// Cria um novo nó
Item *criar_Item(int valor) {
    Item *novo = (Item*)malloc(sizeof(Item));
    if (novo) {
        novo->valor = valor;
        novo->prox = NULL;
    }
    return novo;
}

// Insere no final
Item *Inserefim(Item *cabeca, int valor) {
    Item *novo = criar_Item(valor);
    if (cabeca == NULL) {
        return novo; // Lista estava vazia
    }

    Item *atual = cabeca;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
    return cabeca; // Cabeça não muda
}

// Libera a lista
Item *Libera(Item *cabeca) {
    Item *atual = cabeca;
    while (atual != NULL) {
        Item *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    return NULL; // Retorna NULL para atribuir à variável original
}

// Imprime a lista
void Imprime(const Item *cabeca) {
    const Item *atual = cabeca;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");

  
}


Item *RemoverMeio(Item *cabeca, int valor) {
    // Lista vazia: nada para remover
    if (cabeca == NULL) {
        return NULL;
    }

    // Caso 1: Remoção da cabeça
    if (cabeca->valor == valor) {
        Item *nova_cabeca = cabeca->prox;
        free(cabeca);
        return nova_cabeca;
    }

    // Caso 2: Busca pelo valor no meio ou final
    Item *anterior = cabeca;
    Item *atual = cabeca->prox;

    while (atual != NULL) {
        if (atual->valor == valor) {
            anterior->prox = atual->prox; // "Pula" o nó a ser removido
            free(atual);
            return cabeca; // Cabeça não muda
        }
        anterior = atual;
        atual = atual->prox;
    }

    // Valor não encontrado
    return cabeca;
}