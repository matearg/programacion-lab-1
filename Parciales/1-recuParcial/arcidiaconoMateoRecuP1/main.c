#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

#define CANT_E 100

int cargarArregloTempsRandom(int a[], int cantTemps); // Punto 1
void mostrarArreglo(int a[], int validos); // Punto 1
void ordenarEnPilas(int array[], int validos, Pila * A, Pila * B, Pila * C); // Punto 2 a
void mostrarPila(Pila p); // Punto 2 b
int cantValPilaMayores(Pila p, int valorDado); // Punto 3 a
int sumValPilaMayores(Pila p, int valorDado); // Punto 3 b
void promValPilaMayores(Pila p); // Punto 3 c
int valorMinimoArreglo(int a[], int validos); // Punto 4 a
float porcValMayores(int a[], int validos, int valorDado); // Punto 4 b
void porcValAndValMin(int a[], int validos, int valorDado); // Punto 4 c

int main() // Punto 5
{
    int arregloTemps[CANT_E], validos = 0;

    Pila A, B, C;
    inicpila(&A);
    inicpila(&B);
    inicpila(&C);

    validos = cargarArregloTempsRandom(arregloTemps, 90);

    printf("Arreglo de temperaturas:\n");
    mostrarArreglo(arregloTemps, validos);
    printf("\n\n");

    ordenarEnPilas(arregloTemps, validos, &A, &B, &C);

    printf("Pila A\n");
    mostrarPila(A);
    printf("\n\n");

    printf("Pila B\n");
    mostrarPila(B);
    printf("\n\n");

    printf("Pila C\n");
    mostrarPila(C);
    printf("\n\n");

    promValPilaMayores(C);

    porcValAndValMin(arregloTemps, validos, 25);

    return 0;
}

int cargarArregloTempsRandom(int a[], int cantTemps)
{
    srand(time(NULL));

    int i = 0;

    for(i = 0; i < cantTemps; i++)
    {
        a[i] = rand()%33 - 1;
    }

    return i;
}

void mostrarArreglo(int a[], int validos)
{
    int i = 0;

    for(i = 0; i < validos; i++)
    {
        printf(" %d |", a[i]);
    }
}

void ordenarEnPilas(int array[], int validos, Pila * A, Pila * B, Pila * C)
{
    int i = 0;

    for(i = 0; i < validos; i++)
    {
        if(array[i] < 10)
        {
            apilar(A, array[i]);
        }
        else if(array[i] >= 10 && array[i] <= 20)
        {
            apilar(B, array[i]);
        }
        else
        {
            apilar(C, array[i]);
        }
    }
}

void mostrarPila(Pila p)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        printf("%d c, ", tope(&p));
        apilar(&aux, desapilar(&p));
    }
}

int cantValPilaMayores(Pila p, int valorDado)
{
    int i = 0;

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        apilar(&aux, desapilar(&p));

        if(tope(&aux) > valorDado)
        {
            i++;
        }
    }

    return i;
}

int sumValPilaMayores(Pila p, int valorDado)
{
    int i = 0;

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        apilar(&aux, desapilar(&p));

        if(tope(&aux) > valorDado)
        {
            i += tope(&aux);
        }
    }

    return i;
}

void promValPilaMayores(Pila p)
{
    float prom = 0;
    int cantValMayores = 0, sumValMayores = 0;

    cantValMayores = cantValPilaMayores(p, 25);

    sumValMayores = sumValPilaMayores(p, 25);

    prom = (float)sumValMayores / cantValMayores;

    printf("\nEl promedio de temperaturas mayores a 25 es %0.2f\n", prom);
}

int valorMinimoArreglo(int a[], int validos)
{
    int i = 0, menor = 0, posMenor = 0;

    menor = a[i];
    posMenor = i;

    for(i = 1; i < validos; i++)
    {
        if(a[i] < menor)
        {
            menor = a[i];
            posMenor = i;
        }
    }

    return posMenor;
}

float porcValMayores(int a[], int validos, int valorDado)
{
    int i = 0, j = 0;
    float porc = 0;

    for(i = 0; i < validos; i++)
    {
        if(a[i] > valorDado)
        {
            j++;
        }
    }

    porc = ((float)j * validos) / 100;

    return porc;
}

void porcValAndValMin(int a[], int validos, int valorDado)
{
    int valorMin = 0;
    float porcentaje = 0;

    valorMin = valorMinimoArreglo(a, validos);
    porcentaje = porcValMayores(a, validos, valorDado);

    printf("\nLa temperatura minima es %d y el porcentaje de temperaturas mayores a 25 es %0.2f\n", a[valorMin], porcentaje);
}
