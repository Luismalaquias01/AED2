#include <stdio.h> 
#include "clock.c"

int main(){
    clock *r = criar_clock(23, 59, 59);

    exibir_horario(r);
    incrementar_segundo(r);
    exibir_horario(r);
    incrementar_segundo(r);
    exibir_horario(r);

    destruir_clock(r);
    return 0;
}