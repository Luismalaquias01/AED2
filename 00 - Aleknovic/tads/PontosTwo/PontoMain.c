#include <stdio.h> 
#include <stdlib.h> 
#include "Ponto.c"

int main(){
    float d; 
    float x, y;
    Ponto *p, *q;
    // Ponto r; ERRO 

    p = pto_cria(10,21);
    q = pto_cria(7,25);

    //q -> x = 2; //ERRO

    d = pto_distancia(p,q);

    printf("Distancia entre os pontos: %f\n", d);

 pto_atribui(p, 5.0, 6.0);
 pto_acessa(p, &x, &y);
 pto_atribui(p, 9.0, 21.0);
 pto_acessa(p, &x, &y);


p = pto_cria(51,25);
q = pto_cria(7,25);

 d = pto_distancia(p,q);
 printf("Distancia entre os pontos: %f\n", d);

 pto_libera(q);
 pto_libera(p);

    return 0;
}