#include <stdio.h>
#include <stdlib.h>

int main(){

    int *ptr;

    ptr = (int*) malloc(5 * sizeof(int));

    if(ptr == NULL){
        printf("Erro ao alocar memória");
        return 1;
    }

    for(int i = 0; i <9; i++){
        ptr[i] = i*10;
        printf("%d\n", ptr[i]);
    }

    free(ptr);

    return 0;
}