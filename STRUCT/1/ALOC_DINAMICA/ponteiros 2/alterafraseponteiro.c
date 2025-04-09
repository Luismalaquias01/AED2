#include <stdio.h>

void alterarFrase(char *str) {
    while (*str != '\0') {  // Percorre cada caractere até o fim da string
        if (*str >= 'a' && *str <= 'z') {
            *str -= 32;  // Converte letras minúsculas para maiúsculas
        }
        str++;  // Avança para o próximo caractere
    }
}

int main() {
    char frase[] = "ola mundo";  // Criamos um array mutável
    printf("Antes: %s\n", frase);

    alterarFrase(frase);  // Passamos o ponteiro para a função

    printf("Depois: %s\n", frase);

    return 0;
}
///// AGORA MUDE MAIUSCULO PARA MINUSCULO