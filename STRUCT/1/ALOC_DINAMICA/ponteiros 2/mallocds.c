#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    // Aloca memória para um único inteiro
    ptr = (int *) malloc(sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (ptr == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Atribui um valor à memória alocada
    *ptr = 425555555555558;

    // Exibe o valor armazenado
    printf("Valor armazenado: %d\n", *ptr);

    // Libera a memória alocada
    free(ptr);

    return 0;
}
