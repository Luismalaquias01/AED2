#include <stdio.h>
int dobro(int *a){
    return *a * 2;
}
int main(){
    int valor1 = 10;
    printf("Valor original é: %d\n", valor1);
    valor1 = dobro(&valor1);
    printf("O valor dobrado é: %d\n", valor1);

    return 0;
}
