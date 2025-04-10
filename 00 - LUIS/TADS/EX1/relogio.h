#ifndef RELOGIO_H
#define RELOGIO_H

typedef struct {
    int segundo;
    int minuto;
    int hora;
} Relogio;

Relogio* criarRelogio(int h, int m, int s);

void incrementarSegundo(Relogio* r);

void exibirHorario(Relogio* r);

void destruirRelogio(Relogio* r);

#endif