#include <stdio.h>
#include <ctype.h>  // Para usar tolower()

int contarVogais(char *str) {
    int cont = 0;
    while (*str != '\0') {
        char c = tolower(*str);  // Converte para minúscula para facilitar a verificação
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            cont++;
        }
        str++;  // Avança o ponteiro para o próximo caractere
    }
    return cont;
}

int main() {
    char frase[] = "Ola Mundo";

    printf("Número de vogais: %d\n", contarVogais(frase));

    return 0;
}
