#include <stdio.h>
#include "alearStatic.h"

int main(void)
{
    int num;

    for(int i = 0; i<10; i++)
    {
        num = dado();
        printf("Numero: %d\n", num);
    }

    return 0;
}
