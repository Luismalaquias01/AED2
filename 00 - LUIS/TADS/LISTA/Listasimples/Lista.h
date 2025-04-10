#ifndef LISTA_H
#define LISTA_H

typedef struct ElementoLista Item; // Declaração opaca

// Cria um novo nó / item
Item *criar_Item(int valor);

// Libera toda a lista
Item *Libera(Item *cabeca);

// Insere no final e retorna a cabeça atualizada
Item *Inserefim(Item *cabeca, int valor);

// Imprime a lista
void Imprime(const Item *cabeca);

// Remove um Item do meio da lista
Item *RemoverMeio(Item *cabeca, int valor); 
#endif