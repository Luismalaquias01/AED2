#include <stdio.h>

int main() {
    float num = 5.75;
    float *ptr = &num;  // Ponteiro para float

    printf("Endereço de num: %p\n", ptr);
    printf("Valor de num via ponteiro: %.2f\n", *ptr);

    *ptr = 10.25;  // Modificando o valor usando o ponteiro
    printf("Novo valor de num: %.2f\n", num);

    return 0;
}
