#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

/*
Hacer una función que calcule el promedio de los elementos
de una pila, para ello hacer también una función que calcule
la suma, otra para la cuenta y otra que divida. En total son cuatro
funciones, y la función que calcula el promedio invoca a las otras 3.
*/

void cargarRandom(Pila * p);
void ordenarPila(Pila origen, Pila * destino);
int sumarElementos(Pila p);
int contarElementos(Pila p);
int dividirSumaPorCantElementos(int sumarElementos, int contarElementos);
int calcularPromedio(Pila p);

int main()
{
    Pila dada, ordenada;
    inicpila(&dada);
    inicpila(&ordenada);

    cargarRandom(&dada);

    printf("Dada luego de carga\n");
    mostrar(&dada);

    ordenarPila(dada, &ordenada);

    printf("Pila ordenada\n");
    mostrar(&ordenada);

    printf("Promedio de los elementos de la pila %d\n", calcularPromedio(ordenada));

    return 0;
}

void cargarRandom(Pila * p)
{
    srand(time(NULL));

    int i = 0, cantElementos = 0;

    printf("Cuantos elementos quiere agregar a la pila: ");
    scanf("%d", &cantElementos);

    for(i=0; i<cantElementos;i++)
    {
        apilar(p, rand()%100 + 1);
    }
}

void ordenarPila(Pila origen, Pila * destino)
{
    Pila aux, menor;
    inicpila(&menor);
    inicpila(&aux);

    while(!pilavacia(&origen))
    {
        apilar(&menor, desapilar(&origen));

        while(!pilavacia(&origen))
        {
            if (tope(&origen) < tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&origen));
            }
            else
            {
                apilar(&aux, desapilar(&origen));
            }
        }
        while(!pilavacia(&aux))
        {
            apilar(&origen, desapilar(&aux));
        }
        apilar(destino, desapilar(&menor));
    }
}

int sumarElementos(Pila p)
{
    int suma = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        apilar(&aux, desapilar(&p));
        suma = suma + tope(&aux);
    }

    return suma;
}

int contarElementos(Pila p)
{
    int cantElementos = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        apilar(&aux, desapilar(&p));
        cantElementos++;
    }

    return cantElementos;
}

int dividirSumaPorCantElementos(int sumarElementos, int contarElementos)
{
    float resultado = 0;
    resultado = (float)sumarElementos / (float)contarElementos;

    return resultado;
}

int calcularPromedio(Pila p)
{
    int promedio = 0;

    sumarElementos(p);
    contarElementos(p);

    promedio = dividirSumaPorCantElementos(sumarElementos(p), contarElementos(p));

    return promedio;
}

