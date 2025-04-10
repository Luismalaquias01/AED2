#include "lista.c"
#include <stdio.h> 

int main(){
    Item *lista = NULL; //Criamos aqui uma lista para a estrutura 
    //struct ElementoLista Item chamada lista e precisamos usar o 
    //ponteiro, pois estamos tratando de uma estrutura que será usada
    //e deformada diante de 3 diferentes códigos.
    //Ainda, zeramos a lista para que ela não pegue lixo de memoria

    //Insere elementos 
    lista = Inserefim(lista, 10);
    lista = Inserefim(lista, 20);
    lista = Inserefim(lista, 30);

    //Remove o 20

lista = RemoverMeio(lista,20);
Imprime(lista); //Saída: 10 30 

//remove o 10 (cabeça)
lista = RemoverMeio(lista,10);
Imprime(lista); // Saída: 30

//Remove o 30 (último elemento)
lista = RemoverMeio(lista, 30);
Imprime(lista); //Saída: vazia



return 0;



}