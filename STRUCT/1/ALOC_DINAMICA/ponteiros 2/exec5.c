#include <stdio.h>

int maiorElemento(int *vet, int tamanho) {
    int maior = *vet;  // Assume que o primeiro elemento é o maior
    for (int i = 1; i < tamanho; i++) {
        if (*(vet + i) > maior) {  // Compara o valor atual com o maior encontrado
            maior = *(vet + i);
        }
    }
    return maior;
}

int main() {
    int numeros[] = {3, 7, 2, 8, 6};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    printf("Maior elemento: %d\n", maiorElemento(numeros, tamanho));

    return 0;
}
