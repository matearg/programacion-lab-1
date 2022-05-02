#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

// Hacer una función que pase todos los elementos de una
// pila a otra, pero conservando el orden.

void cargarRandom(Pila * p);
void pasarPilaMismoOrden(Pila * origen, Pila * destino);

int main()
{
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);

    cargarRandom(&dada);

    puts("Dada luego de carga random");
    mostrar(&dada);

    pasarPilaMismoOrden(&dada, &aux);
    puts("Pila dada luego del pasaje");
    mostrar(&dada);

    puts("Pila aux luego del pasaje");
    mostrar(&aux);

    return 0;
}

void cargarRandom(Pila * p)
{
    srand(time(NULL));

    int i = 0, cantElementos;

    printf("Cuantos elementos quiere ingresar: ");
    scanf("%d", &cantElementos);

    for (i = 0; i<cantElementos; i++)
    {
        apilar(p, rand()%100 + 1);
    }

}

void pasarPilaMismoOrden(Pila * origen, Pila * destino)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(origen))
    {
        apilar(&aux, desapilar(origen));
    }
    while(!pilavacia(&aux))
    {
        apilar(destino, desapilar(&aux));
    }
}
