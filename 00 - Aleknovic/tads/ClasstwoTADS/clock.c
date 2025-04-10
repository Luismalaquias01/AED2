#include <stdio.h> 
#include <stdlib.h> 
#include "clock.h"

struct clock{
    int horas;
    int minutos;
    int segundos;

};

clock *criar_clock(int h, int m, int s){

    clock *r = (clock*)malloc(sizeof(clock));

    if(r){
        r -> horas = h;
        r -> minutos = m;
        r -> segundos = s;
         return r;}
}

void destruir_clock(clock *r){
    free(r);
}

void incrementar_segundo(clock *r){
    r -> segundos++;

    if(r -> segundos >= 60){
        r -> segundos = 0;
        r -> minutos++;
    }
        if(r -> minutos >= 60){
            r -> minutos = 0;
            r -> horas++;
        }

            if(r -> horas >= 24){
                r -> horas = 0;
            }
}

void exibir_horario(const clock *r){
    printf("Horario: %02d:%02d:%02d\n", r -> horas, r -> minutos, r -> segundos);
}