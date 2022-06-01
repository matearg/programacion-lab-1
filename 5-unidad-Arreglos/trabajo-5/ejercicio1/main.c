#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

// Crear una función que los cargue, hasta que el usuario lo decida

int cargarArreglos(int l[], char n[][30], int a[]);
void mostrarArreglos(int l[], char n[][30], int a[], int validos);

int main()
{
    int legajos[20];
    char nombres[20][30];
    int anios[20];
    int validos = 0;

    validos = cargarArreglos(legajos, nombres, anios);

    printf("\n\nLista de alumnos:\n");
    mostrarArreglos(legajos, nombres, anios, validos);

    return 0;
}

int cargarArreglos(int l[], char n[][30], int a[])
{
    srand(time(NULL));

    int i = 0, numLegajo = 1;
    char condicion;

    do
    {
        l[i] = numLegajo;
        numLegajo++;

        printf("Ingrese el nombre del alumno: ");
        fflush(stdin);
        scanf("%s", n[i]);

        a[i] = rand()%5 + 1;

        printf("\nDesea agregar otro alumno s/n: ");
        fflush(stdin);
        condicion = getch();
        printf("\n");

        i++;
    }
    while (condicion == 's' && i < 20);

    return i;
}

void mostrarArreglos(int l[], char n[][30], int a[], int validos)
{
    int i = 0;

    printf("Legajos\t Nombre\t Anios\t");

    for(i = 0; i < validos; i++)
    {
        printf("\n%d\t %s\t %d\t", l[i], n[i], a[i]);
    }
}
