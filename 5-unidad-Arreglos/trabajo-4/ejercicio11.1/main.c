#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_E 20
// Ordenar un arreglo según los siguientes métodos:
// Seleccion

int cargarArray(int a[]);
void mostratArray(int a[], int validos);
void ordenarArraySeleccion(int a[], int validos);

int main()
{
    int arreglo[CANT_E], validos = 0;

    validos = cargarArray(arreglo);

    printf("\nArreglo luego de carga\n");
    mostratArray(arreglo, validos);

    ordenarArraySeleccion(arreglo, validos);

    printf("\n\nArreglo luego de ordenar\n");
    mostratArray(arreglo, validos);

    printf("\n\n");
    system("PAUSE");

    return 0;
}

int cargarArray(int a[])
{
    srand(time(NULL));

    int validos = 0, cantElementos;

    printf("Cuantos elementos desea agregar ");
    scanf("%d", &cantElementos);

    for(validos = 0; validos < cantElementos; validos++)
    {
        a[validos] = rand()%101;
    }

    return validos;
}

void mostratArray(int a[], int validos)
{
    int i = 0;

    for(i = 0; i < validos; i++)
    {
        printf("| %d ", a[i]);
    }
}

void ordenarArraySeleccion(int a[], int validos)
{
    int i, j, aux, menor;

    for(i = 0; i < validos; i++)
    {
        menor = i;
        for(j = i+1; j < validos; j++)
        {
            if(a[j] < a[menor])
            {
                menor = j;
            }
        }
        aux = a[i];
        a[i] = a[menor];
        a[menor] = aux;
    }
}
