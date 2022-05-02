#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

// Hacer una función que sume y retorne los dos primeros
// elementos de una pila (tope y anterior), sin alterar su contenido.

void cargarRandom(Pila * p);
void ordenarPila(Pila origen, Pila * destino);
int sumarTopeYAnterior(Pila p);

int main()
{
    Pila dada, ordenada;
    inicpila(&dada);
    inicpila(&ordenada);

    cargarRandom(&dada);

    printf("Dada luego de carga\n");
    mostrar(&dada);

    ordenarPila(dada, &ordenada);

    printf("Pila ordenada\n");
    mostrar(&ordenada);

    printf("La suma entre el tope y su anterior es %d\n", sumarTopeYAnterior(ordenada));

    return 0;
}

void cargarRandom(Pila * p)
{
    srand(time(NULL));

    int i = 0;

    for(i=0;i<10;i++)
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

int sumarTopeYAnterior(Pila p)
{
    int suma = 0;

    Pila aux;
    inicpila(&aux);

    if (!pilavacia(&p))
    {
        apilar(&aux, desapilar(&p));
    }

    return suma = tope(&aux) + tope(&p);
}
