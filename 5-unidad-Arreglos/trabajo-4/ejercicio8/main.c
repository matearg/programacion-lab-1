#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Realizar una función que obtenga el máximo carácter de un arreglo dado.

#define CANT_E 20

int cargarArrayRandom(int a[]);
void mostrarArray(int a[], int validos);
int buscarMayorArray(int a[], int validos);

int main()
{
    int arreglo[CANT_E], validos = 0, mayorElementoArray = 0;

    validos = cargarArrayRandom(arreglo);

    printf("\nArreglo luego de carga\n");
    mostrarArray(arreglo, validos);

    mayorElementoArray = buscarMayorArray(arreglo, validos);

    printf("\n\nEl mayor elemento del arreglo es %d\n\n", mayorElementoArray);

    system("PAUSE");

    return 0;
}

int cargarArrayRandom(int a[])
{
    srand(time(NULL));

    int i = 0, cantElementos = 0;

    printf("Cuantos elementos desea agregar a su arreglo ");
    scanf("%d", &cantElementos);

    for(i=0; i<cantElementos; i++)
    {
        a[i] = rand()%101;
    }

    return i;
}

void mostrarArray(int a[], int validos)
{
    int i = 0;

    for (i=0; i<validos; i++)
    {
        printf("| %d ", a[i]);
    }
}

int buscarMayorArray(int a[], int validos)
{
    int i = 0, mayor;

    mayor = a[i];

    for(i=0; i<validos; i++)
    {
        if (a[i]>mayor)
        {
            mayor = a[i];
        }
    }

    return mayor;
}
