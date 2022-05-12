#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_E 10

// Realizar una funci�n que invierta los elementos
// de un arreglo. (sin utilizar un arreglo auxiliar)

int cargarArray(int a[]);
void mostrarArray(int a[], int validos);
void ordenarArrayInsercion(int a[], int validos);
void invertirArray(int a[], int validos);

int main()
{
    int arreglo[CANT_E];
    int validos;

    validos = cargarArray(arreglo);

    printf("Arreglo luego de carga:\n");
    mostrarArray(arreglo, validos);

    ordenarArrayInsercion(arreglo, validos);

    printf("\n\nArreglo luego de ordenar:\n");
    mostrarArray(arreglo, validos);

    invertirArray(arreglo, validos);

    printf("\n\nArreglo luego de invertir:\n");
    mostrarArray(arreglo, validos);

    printf("\n\n");
    system("PAUSE");

    return 0;
}

int cargarArray(int a[])
{
    srand(time(NULL));

    int i;

    for(i = 0; i < CANT_E; i++)
    {
        a[i] = rand()%101;
    }

    return i;
}

void mostrarArray(int a[], int validos)
{
    int i;

    for(i = 0; i < validos; i++)
    {
        printf("| %d ", a[i]);
    }
}

void ordenarArrayInsercion(int a[], int validos)
{
    int i, j, menor;

    for(i = 1; i < validos; i++)
    {
        menor = a[i];

        j = i;

        while(j > 0 && a[j - 1] > menor)
        {
            a[j] = a[j - 1];

            j--;
        }

        a[j] = menor;
    }
}

void invertirArray(int a[], int validos)
{
    int i, j, aux;

    for(i = 0, j = validos - 1; i < j; i++, j--)
    {
        aux = a[i];

        a[i] = a[j];

        a[j] = aux;
    }
}
