#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

// Hacer una función que inserta en una pila ordenada un nuevo
// elemento, conservando el orden de ésta.

void cargarRandom(Pila * p);
void ordenarPila(Pila origen, Pila * destino);
void insertarElemento(Pila * origen, int * elemento);

int main()
{
    Pila dada, ordenada;
    inicpila(&dada);
    inicpila(&ordenada);

    cargarRandom(&dada);

    printf("Dada luego de carga");
    mostrar(&dada);

    ordenarPila(dada, &ordenada);

    printf("Ordenada");
    mostrar(&ordenada);

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

void ordenarPila(Pila origen, Pila * destino)
{
    Pila aux, menor;
    inicpila(&aux);
    inicpila(&menor);

    while (!pilavacia(&origen))
    {
        apilar(&menor, desapilar(&origen));

        while(!pilavacia(&origen))
        {
            if (tope(&origen) < tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&origen));
            }
            else
            {
                apilar(&aux, desapilar(&origen));
            }
        }
        while(!pilavacia(&aux))
        {
            apilar(&origen, desapilar(&aux));
        }

        apilar(destino, desapilar(&menor));
    }
}

void insertarElemento(Pila * origen, int * elemento)
{}
