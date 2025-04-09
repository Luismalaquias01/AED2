#include <stdio.h>
#include <stdlib.h>
void somador(int *ponteiro, int TAM){
    int soma = 0;
    for(int i = 0; i < TAM; i++){
        soma += ponteiro[i];
    }
    printf("Total da soma foi: %d", soma);
}
int main(){
    int n;
    int *ptr;

    printf("Digite a quantia de elementos: \n");
    scanf("%d", &n);

    ptr = (int *) malloc(n *sizeof(int));

    if (ptr == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        printf("Digite o numero %d: \n", i+1);
        scanf("%d", &ptr[i]);
    }

    somador(ptr, n);

    free(ptr);

    return 0;
}