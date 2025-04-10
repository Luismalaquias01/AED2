#include <stdio.h>
#include <stdlib.h>
#include "relogio.h"
#include "relogio.c"

int main(){

Relogio* horario = criarRelogio(10, 20, 59);
incrementarSegundo(horario);
exibirHorario(horario);
destruirRelogio(horario);

    return 0;
}