#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Hacer una funcion que reciba como parametro un arreglo y la cantidad
// de elementos (validos) cargados en el y calcule la suma de sus elementos.

int cargarArrayUsr(int a[]);
int sumArray(int a[], int v);

int main()
{
    int arreglo[100];

    printf("\n\nLa suma de los elementos del arreglo es %d\n\n", sumArray(arreglo, cargarArrayUsr(arreglo)));

    system("PAUSE");
    system("cls");

    return 0;
}

int cargarArrayUsr(int a[])
{
    int i = 0, validos = 0, condicion;

    do
    {
        printf("Ingrese un elementos al arreglo ");
        scanf("%i", &a[validos]);

        validos++;

        printf("\nPresione una tecla, ESC para salir... \n");
        condicion = getch();
    }
    while (condicion != 27);

    system("cls");

    printf("Arreglo luego de carga\n");

    for(i=0;i<validos;i++)
    {
        printf(" %i |", a[i]);
    }

    return validos;
}

int sumArray(int a[], int v)
{
    int i = 0, suma = 0;

    for(i=0;i<v;i++)
    {
        suma = suma + a[i];
    }

    return suma;
}
