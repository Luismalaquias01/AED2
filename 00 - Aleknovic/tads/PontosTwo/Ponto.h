#ifndef Ponto_H //evita multiplas inclusões 
#define Ponto_H

typedef struct ponto Ponto;

//Cria um novo ponto 
Ponto* pto_cria(float x, float y);

//Libera um ponto;

void pto_libera(Ponto *p);

//Acessa s valores de x e y de um ponto 
void pto_acessa(Ponto *p, float *x, float *y);

//Atribui os valores de x e y a um ponto 
void pto_atribui(Ponto *p, float x, float y);

//Calcula a distância entre dois pontos
float pto_distancia(Ponto *p1, Ponto *p2);

#endif //Sempre que abrir o ifndef eu preciso fechar com o endif 

