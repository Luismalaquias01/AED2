#ifndef CLOCK.H //Evita multiplas inclusões 
#define CLOCK.H

typedef struct clock clock; //declaração opaca, pois não consigo acessar diretamente de outros 
//pontos do meu arquivo 

clock *create_clock(int h, int m, int s);
void destruir_clock(clock *r);
void incrementar_segundo(clock *r);
void exibir_horario(const clock *r);

#endif