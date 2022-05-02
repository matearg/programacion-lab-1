#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Realizar una funcion que sume los elementos de un arreglo de
numeros reales (float) de dimensión 100. (se recomienda hacer una
funcion para cargar y otra para mostrar para este tipo de dato
asociado al arreglo) */

// Carga un array de forma aleatoria
int cargarArrayRandom(float a[]);

// Muestra un array
void mostrarArray(float a[], int v);

// Suma los elementos (float) de un array
float sumarElementosArray(float a[], int v);

int main()
{
    float arreglo[100];
    int validos = 0;

    validos = cargarArrayRandom(arreglo);

    system("cls");

    printf("Array luego de carga\n");
    mostrarArray(arreglo, validos);

    printf("\n\nLa suma de los elementos del array es %.2f\n", sumarElementosArray(arreglo, validos));

    return 0;
}

int cargarArrayRandom(float a[])
{
    srand(time(0));

    int i = 0, validos = 0, cantElementos;

    printf("Cuantos elementos desea en su arreglo? ");
    scanf("%d", &cantElementos);

    for(i=0; i<cantElementos; i++)
    {
        a[validos] = rand()%101;
        validos++;
    }

    return validos;
}

void mostrarArray(float a[], int v)
{
    int i = 0;

    for(i=0; i<v; i++)
    {
        printf(" %.2f |", a[i]);
    }
}

float sumarElementosArray(float a[], int v)
{
    int i = 0;
    float suma = 0;

    for(i=0; i<v; i++)
    {
        suma = suma + a[i];
    }

    return suma;
}
