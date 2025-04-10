#ifndef LISTA_H
#define LISTA_H

typedef struct ElementoLista Item; //Declaração opaca 

//cria um novo nó / item 
Item *criar_Item(int valor);

//Libera toda a lista
Item *Libera(Item *cabeca);

//insere no final e retorna a cabeça atualizada 
Item *Inserefim(Item *cabeca, int valor);

//imptime a lista 
void Imprime(const Item *cabeca);

// Remove um item do meio da lita 
Item *RemoverMeio(Item *cabeca, int valor);

#endif