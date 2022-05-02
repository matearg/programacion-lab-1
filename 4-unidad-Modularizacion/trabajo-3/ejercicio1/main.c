#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

// Hacer una función que permita ingresar varios
// elementos a una pila, tanto como quiera el usuario.

void cargarManual(Pila * p);

int main()
{
    Pila dada;
    inicpila(&dada);

    cargarManual(&dada);

    puts("\nPila dada luego de carga manual");
    mostrar(&dada);

    return 0;
}

void cargarManual(Pila * p)
{
    int elemento;
    char condicion;

    do
    {
        printf("\nIngrese un numero entero: ");
        scanf("%d", &elemento);

        apilar(p, elemento);

        fflush(stdin);
        printf("Desea ingresar un nuevo elemento --> ");
        scanf("%c", &condicion);
    }
    while (condicion == 's');

    printf("\nAdios!\n");
    system("PAUSE");

}
