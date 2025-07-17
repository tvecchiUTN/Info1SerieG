#ifndef __GENERALAFUNC_H
#define __GENERALAFUNC_H

#define GENERALA 0
#define POKER 1
#define FULL 2
#define ESCALERA 3

int queJuegoEs(const int *vecJuego);
int esGenerala(const int *vecJuego);
int esPoker(const int *vecJuego);
int esFull(const int *vecJuego);
int esEscalera(const int *vecJuego);

#endif
