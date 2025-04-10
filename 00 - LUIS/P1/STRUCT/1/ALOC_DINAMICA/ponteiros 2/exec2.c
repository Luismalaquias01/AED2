#include <stdio.h>

void dobrar(int *num) {
    *num *= 2;  // Multiplica o valor armazenado na variável por 2
}

int main() {
    int num = 5;

    printf("Antes: %d\n", num);
    dobrar(&num);
    printf("Depois: %d\n", num);

    return 0;
}
