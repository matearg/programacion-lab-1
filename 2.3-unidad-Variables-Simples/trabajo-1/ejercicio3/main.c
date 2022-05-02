#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos
// aquellos elementos distintos al valor 8

int main()
{
    Pila dada, distintos, auxOcho;
    char condicion;

    inicpila(&dada);
    inicpila(&distintos);
    inicpila(&auxOcho);

    do
    {
        leer (&dada);

        printf("Desea continuar s / n ---> ");
        fflush(stdin);
        scanf("%c", &condicion);
    }
    while (condicion == 's');
    printf("DADA");
    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        if (tope(&dada) != 8)
        {
            apilar(&distintos, desapilar(&dada));
        }
        else
        {
            apilar(&auxOcho, desapilar(&dada));
        }
    }
    printf("DISTINTOS");
    mostrar(&distintos);

    while (!pilavacia(&auxOcho))
    {
        apilar(&dada, desapilar(&auxOcho));
    }
    printf("DADA");
    mostrar(&dada);

    return 0;
}
