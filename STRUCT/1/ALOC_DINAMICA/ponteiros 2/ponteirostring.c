#include <stdio.h>

int main() {
    char palavra[] = "Bem dia";
    char *ptr = palavra;  // ptr aponta para o primeiro caractere da string

    printf("String original: %s\n", ptr);

    *(ptr + 1) = 'o';  // Modifica o segundo caractere de e para o

    printf("String modificada: %s\n", ptr);

    return 0;
}

// por que não podemos utilizar o ponteiro da seguinte forma:
