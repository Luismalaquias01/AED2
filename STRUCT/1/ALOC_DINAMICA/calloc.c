#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int *ptr;
    ptr = (int *) calloc(5, sizeof(int));

    if (ptr == NULL) {
        printf("Erro ao alocar a memória");
        return 1;
    }

    for(int i = 0; i < 5; i++){
        printf("Endereço:%p e valor: %d\n", &ptr[i], ptr[i]);
    }

    free(ptr);


    return 0;
}

// mesma coisa que o malloc, porém inicializa sempre com seus valores zerados, não contendo lixo de memória
