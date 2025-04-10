#include <stdio.h>

int somaVetor(int *vet, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += *(vet + i);  // Acessa cada elemento usando ponteiro
    }
    return soma;
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Soma dos elementos: %d\n", somaVetor(vetor, tamanho));

    return 0;
}
