#include <stdio.h>
#include <stdlib.h>

int main(){

    system("clear");

    int variavel = 10;
    int variavel2 = 20;
    printf ("%d\n", variavel); // valor da variável
    printf ("%p\n", &variavel); // endereço da variável

    printf("==============\n");

    printf ("%d\n", variavel2); // valor da variável
    printf ("%p\n", &variavel2); // endereço da variável

    printf("==============\n");

    int *ptr;
    
    ptr = &variavel2;

    printf("%p\n", &ptr); // Endereço da variável ponteiro
    printf("%p\n", ptr); // Endereço alocado da variável2 dentro do ponteiro

    printf("==============\n");

    printf("O valor da variável no ponteiro é: %d\n", *ptr); // valor alocado no ponteiro


    return 0;
}