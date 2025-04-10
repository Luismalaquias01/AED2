#include "pilha.h"
#include <stdlib.h> 

typedef struct Elemento{
    int dado; 
    struct Elemento* proximo;
} Elemento; //é muito mais fácil eu criar um elemento dessa forma do que eu criar um outro
//elemento com struct de pilha

struct Pilha {
    Elemento* topo; 
};

Pilha* pilha_criar(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void pilha_push(Pilha* p, int valor){
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->dado = valor; 
    novo->proximo = p->topo; //O novo elemento aponta para o antigo topo
    p->topo = novo; //Atualiza o topo
}

int pilha_pop(Pilha* p){
    if(pilha_vazia(p)) return -1; // Pilha vazia 

    Elemento* removido = p->topo;
    int valor = removido->dado;
    p->topo = removido->proximo; //Atualiza o topo
    free(removido);
    return valor;
}

int pilha_top(Pilha* p){
    if (pilha_vazia(p)) return -1;
    return p->topo->dado;
}

int pilha_vazia(Pilha* p){

    return p->topo == NULL;

}

void pilha_destruir(Pilha* p){
    while (!pilha_vazia(p)){
        pilha_pop(p);  //Desempilha todos os elementos 
    }
    free(p); // Libera a estrutura da pilha
}

