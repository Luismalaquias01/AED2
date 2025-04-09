#include <stdio.h>
#include <stdlib.h>

int main (){

    int *ptr;
    int n;
    printf("Digite a quantidade de espaço desejado: ");
    scanf("%d", &n);

    ptr = ((int *) malloc(n *sizeof(int)));

    for(int i = 0; i < n; i++){
        printf("Digite o valor %d: \n", i+1);
        scanf("%d", &ptr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        printf("Endereço de ptr[%d]: %p\n", i, &ptr[i]);
    }

    for(int i = 0; i < n; i++){
        printf("Item %d: %d\n", i+1, ptr[i]);
    }

    free(ptr);

    return 0;
}