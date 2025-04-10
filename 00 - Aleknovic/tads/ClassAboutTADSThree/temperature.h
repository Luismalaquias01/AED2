#ifndef TEMPERATURE_H
#define TEMPERATURE_H

typedef struct temperature temperature; //declaração opaca, pois não consigo acessar diretamente de outros 
//pontos do meu arquivo 

        temperature  *create_clock(int h, int m, int s);

 void inicializar_temperatura(float temp); 
 void aumentar_temperatura(Temperatura *t, float incremento);
 void diminuir_temperatura(Temperatura *t, float decremento);
 void exibir_temperatura(Temperatura t);










#endif