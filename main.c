#include <stdio.h>
#include <stdint.h>
#include "alearStatic.h"

int main(void)
{

    int dadosJugar;

    for(int i = 0; i<500; i++)
    {
         dadosJugar = jugada();
         printf("%d\n", dadosJugar);
         printf("\n");
    }

    //printf("%x\n", dadosJugar);

    return 0;
}
