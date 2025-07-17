#include <stdio.h>
#include <stdint.h>
#include "generalaFunc.h"
#include "alearStatic.h"

static int repetidos(const int *arr, int cdd, int num);

int queJuegoEs(const int *vecJuego)
{
    int ret = -1;

    if(esGenerala(vecJuego) == GENERALA)
    {
        return GENERALA;
    }
    else if(esPoker(vecJuego) == POKER)
    {
        return POKER;
    }
    else if(esFull(vecJuego) == FULL)
    {
        return FULL;
    }
    else if(esEscalera(vecJuego) == ESCALERA)
    {
        return ESCALERA;
    }

    return ret;
}

int esGenerala(const int *vecJuego)
{
    int seRepitio = 0;
    for(int i = 1; i<=TIRADAS; i++)
    {
        seRepitio = repetidos(vecJuego, TIRADAS, i);

        if(seRepitio == 5)
        {
            return GENERALA;
        }
    }
    return -1;
}

int esPoker(const int *vecJuego)
{
    int seRepitio = 0;
    for(int i = 1; i<=TIRADAS; i++)
    {
        seRepitio = repetidos(vecJuego, TIRADAS, i);

        if(seRepitio == 4)
        {
            return POKER;
        }
    }

    return -1;
}

int esFull(const int *vecJuego)
{
    int vecRepet[TIRADAS];
    int hayTres = 0, hayDos = 0;

    int seRepitio = 0;
    for(int i = 1; i<=TIRADAS; i++)
    {
        seRepitio = repetidos(vecJuego, TIRADAS, i);
        vecRepet[i] = seRepitio;
    }

    for(int i = 0; i<TIRADAS; i++)
    {
        if(vecRepet[i] == 3)
        {
            hayTres = 1;
        }
        if(vecRepet[i] == 2)
        {
            hayDos = 1;
        }
    }

    if(hayTres && hayDos)
    {
        return FULL;
    }

    return -1;

}

int esEscalera(const int *vecJuego)
{
    int hayUno = 0;
    int hayDos = 0;
    int hayTres = 0;
    int hayCuatro = 0;
    int hayCinco = 0;
    int haySeis = 0;

    for(int i = 0; i < TIRADAS; i++)
    {
        switch(vecJuego[i])
        {
            case 1:
                hayUno = 1;
                break;
            case 2:
                hayDos = 1;
                break;
            case 3:
                hayTres = 1;
                break;
            case 4:
                hayCuatro = 1;
                break;
            case 5:
                hayCinco = 1;
                break;
            case 6:
                haySeis = 1;
                break;
        }
    }

    if(hayUno && hayDos && hayTres && hayCuatro && hayCinco && !haySeis)
    {
        return ESCALERA;
    }else if(!hayUno && hayDos && hayTres && hayCuatro && hayCinco && haySeis)
    {
        return ESCALERA;
    }

    return -1;
}

static int repetidos(const int *arr, int cdd, int num)
{
    int repet = 0;
    for(int i = 0; i<cdd; i++)
    {
        if(arr[i] == num)
        {
            repet++;
        }
    }
    return repet;
}
