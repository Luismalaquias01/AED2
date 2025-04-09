#include <stdio.h>

void alterarFrase(char *str){
    while (*str != '\0') {
        if (*str >= 'A' && *str <='Z') {
            *str += 32;
        }
        str++;
    }
}

int main (void) {

    char frase[] = "OLA MUNDO";
    printf("Antes: %s\n", frase);

    alterarFrase(frase);

    printf("Depois: %s\n", frase);

    return 0;

}