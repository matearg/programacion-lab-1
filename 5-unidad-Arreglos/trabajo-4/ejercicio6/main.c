#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Realizar una función que indique si un elemento dado se
// encuentra en un arreglo de caracteres.

// Carga un arreglo con caracteres
int cargarArregloUsr(char a[]);

// Muestra un arreglo
void mostrarArreglo(char a[], int v);

// Buscar un caracter en un arreglo
void buscarCaracter(char a[], int v);

int main()
{
    char arreglo[100];
    int validos = 0;

    validos = cargarArregloUsr(arreglo);

    system("cls");

    printf("Arreglo luego de carga\n");
    mostrarArreglo(arreglo, validos);

    buscarCaracter(arreglo, validos);

    return 0;
}

int cargarArregloUsr(char a[])
{
    int condicion;
    int validos = 0;

    do
    {
        printf("\nIngrese un caracter al arreglo ");
        fflush(stdin);
        scanf("%c", &a[validos]);

        validos++;

        printf("\nPresione una tecla, ESC para salir...");
        condicion = getch();
    }
    while (condicion != 27);

    return validos;
}

void mostrarArreglo(char a[], int v)
{
    int i = 0;

    for(i=0;i<v;i++)
    {
        printf(" %c |", a[i]);
    }
}

void buscarCaracter(char a[], int v)
{
    int i = 0;
    char caracter;

    printf("\nQue caracter quiere buscar ");
    fflush(stdin);
    scanf("%c", &caracter);

    for(i=0;i<v;i++)
    {
        if (a[i] == caracter)
        {
            printf("\nSe encontro el caracter buscado\n");
            break;
        }
        else
        {
            continue;
        }
    }
}
