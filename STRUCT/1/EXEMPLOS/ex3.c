#include<stdio.h>
#define TAM 3
int soma(int *vet[]){
    int somador = 0;
    for(int i = 0; i < TAM; i++){
        somador += *vet[i];
    }
    return somador;
}
int main(){
    int vet[TAM] = {1,2,3};
    int *ptr[TAM];

    for(int i = 0; i < TAM; i++){
        ptr[i] = &vet[i];
    }
    int resultado = soma(ptr);

    printf("O resultado da soma foi: %d", resultado);

    return 0;
}