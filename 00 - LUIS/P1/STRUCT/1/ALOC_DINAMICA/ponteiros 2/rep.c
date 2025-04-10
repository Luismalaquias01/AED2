#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    // Aloca memória para um inteiro
    ptr = (int *) malloc(sizeof(int));

    if (ptr == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    *ptr = 42,15; // Atribui um valor à memória alocada
    printf("Valor armazenado: %d %d\n", *ptr,*ptr);
    // Libera a memória alocada
    free(ptr);

    // Boa prática: evitar ponteiro solto
    ptr = NULL;

    return 0;
}
