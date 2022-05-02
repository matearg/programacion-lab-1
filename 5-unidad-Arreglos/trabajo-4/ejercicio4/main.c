#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

/* Hacer una funcion que reciba como parametro un arreglo, la cantidad
de elementos (validos) cargados en el y una Pila. La funcion
debe copiar los elementos del arreglo en la pila. */

// Carga y muestra un array
int cargarArrayRandom(int a[]);

// Pasa un array a una pila
void arregloAPila(int a[], int v, Pila * p);

int main()
{
    int arreglo[100];
    Pila dada;
    inicpila(&dada);

    printf("\nDada luego de inicializar");
    mostrar(&dada);

    arregloAPila(arreglo, cargarArrayRandom(arreglo), &dada);

    printf("\n\nDada luego de pasaje");
    mostrar(&dada);

    return 0;
}

int cargarArrayRandom(int a[])
{
    srand(time(NULL));

    int i = 0, validos = 0, cantElementos;

    printf("Cantidad de elementos del arreglo: ");
    scanf("%d", &cantElementos);

    for(i=0; i<cantElementos; i++)
    {
        a[validos] = rand()%101;
        validos++;
    }

    system("cls");
    printf("Arreglo luego de carga\n");

    for(i=0; i<validos; i++)
    {
        printf(" %i |", a[i]);
    }

    return validos;
}

void arregloAPila(int a[], int v, Pila * p)
{
    int i=0;

    for(i=0; i<v; i++)
    {
        apilar(p, a[i]);
    }
}
