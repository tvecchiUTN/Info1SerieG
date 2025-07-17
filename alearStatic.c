#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "alearStatic.h"

int dado(void)
{
    int ret;
    static int semilla_inicializada = 0;
    if (!semilla_inicializada) {
        srand(time(NULL));
        semilla_inicializada = 1;
    }

    ret = rand() % 6;
    if(ret == 0)
    {
        ret = 6;
    }

    return ret;
}
