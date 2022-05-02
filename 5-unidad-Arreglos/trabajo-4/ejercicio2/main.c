#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define CANT_E 100

// Hacer una funcion que reciba como parametro un arreglo y la cantidad
// de elementos (validos) cargados en el y los muestre por pantalla.

int cargarArrayUsr(int a[]);
void mostrarArray(int a[], int v);

int main()
{
    int arreglo[CANT_E];

    mostrarArray(arreglo, cargarArrayUsr(arreglo));

    return 0;
}

int cargarArrayUsr(int a[])
{
    srand(time(NULL));

    int validos = 0;
    // int i = 0, cantElementosUsr; // para cargar random
    int condicion;

    do
    {
        printf("\nIngrese un elemento al array ");
        scanf("%i", &a[validos]);

        validos++;

        printf("\nPresione una tecla, ESC para salir...");
        condicion = getch();
    }
    while(condicion != 27);

    // para cargar random
    // printf("Cuantos elementos desea ingresar ");
    // scanf("%d", &cantElementosUsr);
    //
    // for(i=0;i<cantElementosUsr;i++)
    // {
    //     a[validos] = rand()%11;
    //     validos++;
    // }

    return validos;
}

void mostrarArray(int a[], int v)
{
    int i = 0;

    system("cls");

    printf("Arreglo luego de carga\n");

    for(i=0; i<v; i++)
    {
        printf(" %i |", a[i]);
    }
}
