#include <stdio.h> //cabeça seria como se fosse o cabeçalho
#include <stdlib.h> 
#include "Lista.h"

//definição de struct (visivel apenas no .c)
struct ElementoLista{
    int valor;
    struct ElementoLista *prox;   
};

//cria um novo nó 
Item *criar_Item(int valor){
    Item *novo = (Item*) malloc (sizeof(Item));
    if(novo) {
        novo->valor = valor;
        novo->prox = NULL;
    }
    return novo;
}

//insere no final 
Item *Inserefim(Item *cabeca, int valor){
    Item *novo = criar_Item(valor);
    if(cabeca == NULL){
        return novo; //Lista estava vazia
    }

    Item *atual = cabeca; //Como se fosse uma variável temp
    while(atual->prox != NULL){
        atual = atual->prox;
    }
    atual->prox = novo;
    return cabeca; //cabeça não muda
}

//Libera a lista 
// Função para liberar todos os nós de uma lista encadeada
Item *Libera(Item *cabeca){
    Item *atual = cabeca;      // Começa pelo primeiro nó da lista
    while(atual != NULL){      // Enquanto não chegar ao fim da lista
        Item *temp = atual;    // Guarda o nó atual temporariamente
        atual = atual->prox;   // Avança para o próximo nó
        free(temp);            // Libera a memória do nó atual
    }
    return NULL;               // Retorna NULL para atualizar o ponteiro da cabeça
}

//imprime a lista 
void Imprime(const Item *cabeca){
    const Item *atual = cabeca;
    while (atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

Item *RemoverMeio(Item *cabeca, int valor){
    //Lista vazia, nada para remover
    if(cabeca == NULL){
        return NULL;
    }

    //caso 1: remoção da cabeça 
    if(cabeca->valor == valor){
        Item *nova_cabeca = cabeca -> prox;
        free(cabeca);
        return nova_cabeca;
    }

    // caso 2: Busca pelo valor no meio ou final 
    Item *anterior = cabeca;
    Item *atual = cabeca->prox; 

    while (atual != NULL){
        if(atual->valor == valor){
            anterior->prox = atual -> prox;//"pula" o nó  a ser removido
            free(atual);
            return cabeca; //cabeça não muda
        }
        anterior = atual;
        atual = atual -> prox;
    }

    //valor não encontrado 
    return cabeca;
}