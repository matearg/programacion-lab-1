#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define CANT_E 100

int cargarArrayUsr(int a[]);
int cargarArrayRandom(int a[]);
void mostrarArray(int a[], int v);
int buscarMenor(int a[], int v);


int main()
{
    int arreglo[CANT_E], validos = 0;

    validos = cargarArrayRandom(arreglo);

    system("cls");

    printf("Arreglo luego de carga\n");
    mostrarArray(arreglo, validos);

    printf("\n\nEl menor elemento del arreglo es %d\n\n", buscarMenor(arreglo, validos));

    system("PAUSE");
    system("cls");

    return 0;
}

int cargarArrayUsr(int a[])
{
    int validos = 0;
    char condicion;

    do
    {
        printf("Ingrese un elemento al arreglo ");
        scanf("%i", &a[validos]);

        validos++;

        printf("Presione una tecla, ESC para salir...");
        condicion = getch();
    }
    while(condicion != 27);

    return validos;
}

int cargarArrayRandom(int a[])
{
    srand(time(0));

    int validos = 0, i = 0, cantElementos;

    printf("Cuantos elementos desea agregar ");
    scanf("%d", &cantElementos);

    for(i=0; i<cantElementos; i++)
    {
        a[i] = rand()%101;

        validos++;
    }

    return validos;
}

void mostrarArray(int a[], int v)
{
    int i = 0;

    for(i=0; i<v; i++)
    {
        printf("| %i ", a[i]);
    }
}

int buscarMenor(int a[], int v)
{
    int i = 0, menor = 0;

    menor = a[i];

    for(i=0; i<v; i++)
    {
        if (a[i]<menor)
        {
            menor = a[i];
        }
    }

    return menor;
}
