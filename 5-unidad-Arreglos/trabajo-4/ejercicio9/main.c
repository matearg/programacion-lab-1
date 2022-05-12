#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_E 4

// Realizar una función que determine si un arreglo es capicúa.

int cargarArrayUsr(int a[]);
void mostrarArray(int a[], int validos);
void capicua(int a[], int validos);

int main()
{
    int arreglo[CANT_E];
    int arregloDos[CANT_E];
    int validos = 0, validosDos = 0;

    validos = cargarArrayUsr(arreglo);
    system("cls");

    validosDos = cargarArrayUsr(arregloDos);
    system("cls");

    printf("\nArrelgo luego de cargar:\n");
    mostrarArray(arreglo, validos);

    capicua(arreglo, validos);

    printf("\n\nArrelgoDos luego de cargar:\n");
    mostrarArray(arregloDos, validosDos);

    capicua(arregloDos, validosDos);

    return 0;
}

int cargarArrayUsr(int a[])
{
    int i, valor;

    for(i = 0; i < CANT_E; i++)
    {
        printf("Ingrese un valor al arreglo (%d de %d) ", i, CANT_E);
        scanf("%d", &valor);

        a[i] = valor;
    }

    return i;
}

void mostrarArray(int a[], int validos)
{
    int i = 0;

    for(i = 0; i < validos; i++)
    {
        printf("| %d ", a[i]);
    }

}

void capicua(int a[], int validos)
{
    int i = 0;

    for(i = 0; i < validos / 2; i++)
    {
        if(a[i] != a[validos - i - 1])
        {
            printf("\nEl arreglo no es capicua\n");
            return;
        }
    }

    printf("\nEl arreglo es capicua\n");
    return;
}
