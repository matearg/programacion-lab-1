#include <stdio.h>
#include <stdlib.h>

#define CANT_E 20

// Realizar una función que inserte un carácter en un
// arreglo ordenado alfabéticamente,
// conservando el orden.

int cargarArreglo(char a[]);
void mostrarArrelgo(char a[], int validos);
void insertarElemento(char a[], char elementoInsertado, int validos);

int main()
{
    int validos = 0;
    char arreglo[] = {'a', 'c', 'd', 'e'}, elementoAInsertar = 'b';

    //validos = cargarArreglo(arreglo);
    validos = 5;

    printf("\nArrelgo luego de carga\n");
    mostrarArrelgo(arreglo, validos);

    insertarElemento(arreglo, elementoAInsertar, validos);
    printf("\n\nArrelgo luego de insertar\n");
    mostrarArrelgo(arreglo, validos);

    printf("\n\n");
    system("PAUSE");

    return 0;
}

int cargarArreglo(char a[])
{
    char condicion = 's';
    int validos = 0;

    do
    {
        printf("Ingrese un caracter al arreglo ");
        fflush(stdin);
        scanf("%c", &a[validos]);

        validos++;

        printf("Desea continuar s/n ");
        fflush(stdin);
        scanf("%c", &condicion);
    }
    while (condicion == 's');

    return validos;
}

void mostrarArrelgo(char a[], int validos)
{
    int i = 0;

    for(i=0; i<validos; i++)
    {
        printf("| %c ", a[i]);
    }
}

void insertarElemento(char a[], char elementoInsertado, int validos)
{}
