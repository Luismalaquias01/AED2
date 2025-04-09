#include <stdio.h>

int troca(int *a, int *b){
    int temp = *a; // armazenando o valor de a temporariamente
    *a = *b; // atribuindo o valor de b em a
    *b = temp; // atribuindo o valor antigo de a armazenado em temp agora em b
    return printf("a = %d, b = %d", *a,*b); // mostrando na tela os valores trocados
}
int main(){
    int x = 10;
    int y = 20;
    troca(&x,&y);
    return 0;
}