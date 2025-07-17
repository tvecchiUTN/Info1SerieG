#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "alearStatic.h"
#include "generalaFunc.h"

//------------------------------------------Ejercicio1----------------------------------------------
int dado(void)
{
    int ret;
    static int semilla_inicializada = 0;
    if (!semilla_inicializada) {
        srand(time(NULL));
        semilla_inicializada = 1;
    }

    ret = (rand() % 6)+1;

    return ret;
}
//------------------------------------------Ejercicio1----------------------------------------------

//------------------------------------------Ejercicio2----------------------------------------------
void cubilete(void)
{
    int res;
    for(int i = 0; i<TIRADAS; i++)
    {
        res = dado();
        printf("%d\n", res);
    }
}
//------------------------------------------Ejercicio2----------------------------------------------

//------------------------------------------Ejercicio3----------------------------------------------
int cubileteDos(uint8_t indicacion)
{
    int ret = 0;

    uint8_t mask = 0x01;
    uint8_t ultimoBit;
    for(int i = 0; i<TIRADAS; i++)
    {
        ultimoBit = indicacion & (mask << i);
        ultimoBit >>= i;

        if(ultimoBit == 0x00)
        {
            ret++;
        }
    }

    return ret;
}
//-----------------------------------------Ejercicio3-----------------------------------------------

//------------------------------------------Ejercicio4----------------------------------------------
uint16_t cubileteTres()
{

    uint16_t valDado;
    uint16_t res= 0x00;


    for(int i = 0; i<TIRADAS; i++)
    {
        valDado = dado();
        res = res | (valDado << (i*3));
    }

    return res;
}
//------------------------------------------Ejercicio4---------------------------------------------------

//------------------------------------------Ejercicio5---------------------------------------------------
int jugada(void)
{
    uint16_t juego = cubileteTres();
    int juegoVec[TIRADAS];
    uint16_t mask = 0x07;

    int ret;

    for(int i = 0; i<TIRADAS; i++)
    {
        juegoVec[i] = juego & (mask << (i*3));
        juegoVec[i] >>= (i*3);

        printf("%d\n", juegoVec[i]);
    }
    ret = queJuegoEs(juegoVec);

    if(ret == GENERALA)
    {
        printf("GENERALA!!\n");
        return ret;
    }else if(ret == POKER)
    {
        printf("POKER!!\n");
        return ret;
    }else if(ret == FULL)
    {
        printf("FULL!!\n");
        return ret;
    }else if(ret == ESCALERA)
    {
        printf("ESCALERA!!\n");
        return ret;
    }
    else{
        printf("Intentelo de nuevo\n");
        return ret;
    }
}
//------------------------------------------Ejercicio5---------------------------------------------------


