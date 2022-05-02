#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Desarrollar una función que devuelva un valor RANDOM en el rango de 0 a 100.

int devolverRandom();

int main()
{
    printf("Valor random %d\n", devolverRandom());

    return 0;
}

int devolverRandom()
{
    srand(time(NULL));

    int num = 0;

    num = rand()%100 + 1;

    return num;
}

