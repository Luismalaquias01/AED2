#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;  // Ponteiro apontando para o primeiro elemento do array

    for(int i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, *(ptr + i));  // Acessando valores via ponteiro
    }

    return 0;
}
