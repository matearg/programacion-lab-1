#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

// Hacer una función que pase todos los elementos de una pila a otra.

void cargarRandom(Pila * p);
void pasarPilaInvertida(Pila * origen, Pila * destino);

int main()
{
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);

    cargarRandom(&dada);

    puts("Dada luego de carga random");
    mostrar(&dada);

    pasarPilaInvertida(&dada, &aux);
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

void pasarPilaInvertida(Pila * origen, Pila * destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}
