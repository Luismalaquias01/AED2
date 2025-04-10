#include <stdlib.h> 
#include <math.h>
#include "Ponto.h"

//Definição do tipo de dados 
struct ponto{
    float x;
    float y;
};

Ponto * pto_cria(float x, float y){ //Nessa parte, é como se eu estivesse criando já alguma variável para
//a minha struct, por isso eu só declaro Ponto *, pois na verdade eu estaria mandando Ponto *p, 
//Que é a minha variável nova criada.
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));
    if(p != NULL){
        p -> x = x;
        p -> y = y;
    }
    printf("%f, %f\n", p -> x, p -> y );
    printf("%f, %f\n", x, y );
    return p;
    
}

//Libera a memória alocada para um ponto
void pto_libera(Ponto *p){
    free(p);
}

//Recupera, por referência, o valor de um ponto 
void pto_acessa(Ponto *p, float *x, float *y){
    *x = p -> x;
    *y = p -> y;

    printf("%f, %f\n", p->x, p->y );
    printf("%f, %f\n", *x, *y );
}

//Atribui a um ponto as coordenadas "x" e "y"
void pto_atribui(Ponto *p, float x, float y){
        p -> x = x;
        p -> y = y;

        printf("%f, %f\n", p -> x, p -> y );
        printf("%f, %f\n", x, y );
}

//Calcula a distância entre dois pontos 
float pto_distancia(Ponto *p1, Ponto *p2){
    float dx = p1 -> x - p2 -> x;
    float dy = p1 -> y - p2 -> y;
    return sqrt(dx * dx + dy * dy);
}

