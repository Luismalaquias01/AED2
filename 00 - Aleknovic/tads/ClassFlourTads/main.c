#include "pilha.c"
#include <stdio.h> 

int main(){
    Pilha* pilha = pilha_criar();

    // Empilha valores 
    pilha_push(pilha, 10);
    pilha_push(pilha, 20);
    pilha_push(pilha, 30);


    //Mostra o topo 
    printf("Topo: %d\n", pilha_top(pilha)); //30

    //Desempilha e mostra 
    printf("Pop: %d\n", pilha_pop(pilha)); //30
    printf("Pop: %d\n", pilha_pop(pilha)); //20

    // verifica se está vazia 
    printf("Vazia? %s\n", pilha_vazia(pilha) ? "Sim" : "Nao"); //nao 
    printf("Pop: %d\n", pilha_pop(pilha));
    printf("Vazia? %s\n", pilha_vazia(pilha) ? "Sim" : "Nao"); //Nao
    pilha_destruir(pilha);
    return 0;
}