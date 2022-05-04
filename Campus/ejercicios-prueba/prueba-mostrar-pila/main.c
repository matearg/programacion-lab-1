#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

void cargarPilaRandom(Pila * p, int cantElementos);
void ordenarPila(Pila origen, Pila * destino);
void mostrarPila(Pila p);

int main()
{
    int cantElementos;

    Pila dada, ordenada;
    inicpila(&dada);
    inicpila(&ordenada);

    system("cls");

    printf("Cuantos elementos desea agregar a su pila ");
    scanf("%d", &cantElementos);

    cargarPilaRandom(&dada, cantElementos);

    system("cls");

    printf("Dada luego de carga");
    mostrarPila(dada);

    ordenarPila(dada, &ordenada);

    printf("\nPila ordenada");
    mostrarPila(ordenada);

    system("PAUSE");
    system("cls");

    return 0;
}

void cargarPilaRandom(Pila * p, int cantElementos)
{
    srand(time(0));

    int i = 0;

    for(i=0;i<cantElementos;i++)
    {
        apilar(p, rand()%101);
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

void mostrarPila(Pila p)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        apilar(&aux, desapilar(&p));
    }

    printf("\nBase .............................................. Tope\n\n");
    while(!pilavacia(&aux))
    {
        apilar(&p, desapilar(&aux));

        printf("| %d ", tope(&p));
    }
    printf("\n\nBase .............................................. Tope\n");
}
