#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    // Aloca memória para 5 inteiros
    ptr = (int *) malloc(5 * sizeof(int));

    if (ptr == NULL) {
        printf("Falha na alocação de memória\n");
        return 1;
    }

    // Usando a memória alocada
    for (int i = 0; i < 9; i++) {
        ptr[i] = i * 10;
        printf("%d ", ptr[i]);
    }

    // Liberando memória
    free(ptr);

    return 0;
}
