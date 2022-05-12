#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ordenar un arreglo según los siguientes métodos:
// Insercion

#define CANT_E 20

int cargarArreglo(int a[]);
void mostrarArrelgo(int a[], int validos);
void ordenarArrelgoInsercion(int a[], int validos);

int main()
{
    int arreglo[CANT_E], validos = 0;

    validos = cargarArreglo(arreglo);

    printf("\nArreglo luego de carga\n");
    mostrarArrelgo(arreglo, validos);

    ordenarArrelgoInsercion(arreglo, validos);
    printf("\n\nArreglo ordenado por insercion\n");
    mostrarArrelgo(arreglo, validos);

    printf("\n\n");
    system("PAUSE");

    return 0;
}

int cargarArreglo(int a[])
{
    srand(time(NULL));

    int validos = 0, cantElementos = 0;

    printf("Cuantos elementos desea agregar ");
    scanf("%d", &cantElementos);

    for(validos = 0; validos < cantElementos; validos++)
    {
        a[validos] = rand()%101;
    }

    return validos;
}

void mostrarArrelgo(int a[], int validos)
{
    int i = 0;

    for(i = 0; i < validos; i++)
    {
        printf("| %d ", a[i]);
    }
}

void ordenarArrelgoInsercion(int a[], int validos)
{
    int i = 0, j = 0, menor = 0;

    for (i = 1; i < validos; i++)
    {
        menor = a[i];

        j = i;

        while (j > 0 && a[j - 1] > menor)
        {
            a[j] = a[j - 1];

            j--;
        }

        a[j] = menor;
    }
}
