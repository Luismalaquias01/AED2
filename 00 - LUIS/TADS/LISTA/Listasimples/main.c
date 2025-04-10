#include "Lista.c"
#include <stdio.h>


int main() {
    Item *lista = NULL;

    // Insere elementos
    lista = Inserefim(lista, 10);
    lista = Inserefim(lista, 20);
    lista = Inserefim(lista, 30);

    Imprime(lista);

    // Remove o 20 
    lista = RemoverMeio(lista, 20);
    Imprime(lista); // Saída: 10 30

    // Remove o 10 (cabeça)
    lista = RemoverMeio(lista, 10);
    Imprime(lista); // Saída: 30

    // Remove o 30 (último elemento)
    lista = RemoverMeio(lista, 30);
    Imprime(lista); // Saída: (vazia)

    return 0;
}