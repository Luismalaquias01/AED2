#include <stdio.h>  //Esse é o código que o meu usuário irá ver 

#include "ponto.c" //Inclui o tad 

int main(){
    Ponto* p1 = criarPonto(2.0, 3.0);
    exibirPonto(p1);

    moverPonto(p1, 1.5, -2.0);
    exibirPonto(p1);

    destruirPonto(p1); //Libera a memória 
    return 0;
}