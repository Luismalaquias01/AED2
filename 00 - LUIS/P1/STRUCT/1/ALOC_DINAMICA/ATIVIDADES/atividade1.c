#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr;
    ptr = (int *) malloc(1 * sizeof(int));

    printf("Digite um valor desejado:");
    scanf("%d", ptr);

    printf("O valor é: %d", *ptr);

    free(ptr);

    return 0;
}