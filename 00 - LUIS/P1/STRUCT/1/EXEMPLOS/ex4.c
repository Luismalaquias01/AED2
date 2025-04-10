#include <stdio.h>
#define TAM 4

int volta_Maior(int *vetor[]){
    int maior = *vetor[0];
    for(int i = 1; i < TAM; i++){
        if(*vetor[i] > maior){
        maior = *vetor[i];
        }
    }
    return maior;
}

int main(){
    int vet[TAM] = {3,5,9,15};
    int *ptr[TAM];

    for(int i = 0; i < TAM; i++){
        ptr[i] = &vet[i];
    }
    int resultado = volta_Maior(ptr);
    printf("%d", resultado);
    return 0;
}

