#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    // Alocando memória para um array de n inteiros
    int *array = (int *)malloc(n * sizeof(int));

    // Verificando se a alocação foi bem-sucedida
    if (array == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Preenchendo o array
    for (int i = 0; i < n; i++) {
        array[i] = i * 2; // Exemplo: preenche com valores pares
    }

    // Exibindo o array
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberando a memória alocada
    free(array);

    return 0;
}