#include <stdio.h> 
#include <stdlib.h> 
#include "ponto.h" //Inclui o cabeçalho do tad 

//definção interna da estrutura (oculta no ponto.h)
struct Ponto {
    float x, y;
};

//Função para criar um ponto
Ponto* criarPonto(float x, float y){
    Ponto* p = (Ponto*) malloc (sizeof(Ponto));
    if(p != NULL){
        p->x = x;
        p->y = y;
    }
    return p;
}

//Função para destruir um ponto(liberar a memória)

void destruirPonto(Ponto* p){
    free(p);
}

//função para mover um ponto 

void moverPonto(Ponto* p, float dx, float dy) {
    if(p != NULL){
        p->x += dx;
        p->y += dy;
    }
}

//função para exibir um ponto

void exibirPonto(Ponto* p){
    if(p != NULL){
        printf("Ponto: (%.2f, %.2f)\n", p->x, p->y);
    }
}

