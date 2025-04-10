#ifndef PILHA_H
#define PILHA_H

typedef struct Pilha Pilha;

//cria uma pilha vazia 
Pilha* pilha_criar();

//Empilha um elenco (push)
void pilha_push(Pilha* p, int valor);

//Desempilha  eretorna o elemento do topo (pop)
int pilha_pop(Pilha* p);

//Retorna o elemento do topo sem remover (peek)
int pilha_top(Pilha* p);

//Verifica se a pilha está vaiza 
int pilha_vazia(Pilha* p);

//Libera a memoria da pilha
void pilha_destruir(Pilha* p);

#endif