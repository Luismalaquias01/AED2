#include <stdio.h>

void trocar(int *x, int *y) {
    int temp = *x;  // Armazena o valor de x em temp
    *x = *y;        // Atribui o valor de y para x
    *y = temp;      // Atribui o valor de temp para y
}

int main() {
    int a = 10, b = 20;
    
    printf("Antes da troca: a = %d, b = %d\n", a, b);
    trocar(&a, &b);
    printf("Depois da troca: a = %d, b = %d\n", a, b);
    
    return 0;
}
