#include <stdio.h>
#include <stdlib.h>
#include "relogio.h"

Relogio* criarRelogio(int h, int m, int n){
    Relogio* r = (Relogio*) malloc(sizeof(Relogio));
    if(r!=NULL){
        r->hora = h;
        r->minuto = m;
        r->segundo = s;
    }

    return r;

}

void incrementarSegundo(Relogio* r){

    if (r!=NULL){
        r->segundo++;
        if(r->segundo>=60){
            r->segundo = 0;
            r->minuto++;
            if(r->minuto >= 60){
                r->minuto=0;
                r->hora++;

            }
        }
    }

}