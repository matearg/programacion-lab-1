#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

/// Encontrar el menor elemento de una pila y guardarlo en otra.
/// (sin variables enteras, solo pilas)

int main()
{

    srand(time(NULL));

    Pila dada, menor, aux;
    inicpila(&dada);
    inicpila(&menor);
    inicpila(&aux);

    int i = 0, cantElementos = 0;

    printf("Cantidad de elementos de la pila: ");
    scanf("%i", &cantElementos);

    for (i = 0; i < cantElementos; i++)
    {
        apilar(&dada, (rand()%100) + 1);
    }

    puts("Pila Dada despues de cargar");
    mostrar(&dada);

    if (!pilavacia(&dada))
    {
        apilar(&menor, desapilar(&dada));
        while (!pilavacia(&dada))
        {
            if (tope(&dada) < tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&dada));
            }
            else
            {
                apilar(&aux, desapilar(&dada));
            }
        }
        while(!pilavacia(&aux))
        {
            apilar(&dada, desapilar(&aux));
        }
    }

    puts("Pila Menor");
    mostrar(&menor);

    puts("Dada luego de sacar menor");
    mostrar(&dada);

    return 0;
}
