#include <stdio.h>

int main() {
    int num = 10;
    int *ptr; // Declaramos um ponteiro para inteiro
    
    ptr = &num; // O ponteiro recebe o endereço de 'num'

    printf("Valor de num: %d\n", num);
    printf("Endereço de num: %p\n", &num);
    printf("Valor armazenado em ptr: %p\n", ptr);
    printf("Valor apontado por ptr: %d\n", *ptr); // Desreferenciação

    return 0;
}
