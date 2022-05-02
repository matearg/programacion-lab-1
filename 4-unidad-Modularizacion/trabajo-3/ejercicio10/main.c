#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

// Hacer una función que reciba una pila con números de
// un solo dígito (es responsabilidad de quien usa el programa)
// y que transforme esos dígitos en un número decimal.

void cargarRandom(Pila * p);
void ordenarPila(Pila origen, Pila * destino);
int mostrarElemetosComoEntero(Pila p);

int main()
{
    Pila dada, ordenada;
    inicpila(&dada);
    inicpila(&ordenada);

    cargarRandom(&dada);

    printf("\nDada luego de cargar");
    mostrar(&dada);

    ordenarPila(dada, &ordenada);

    printf("Pila ordenada");
    mostrar(&ordenada);

    printf("Elementos de la pila como entero %d\n\n", mostrarElemetosComoEntero(ordenada));

    system("PAUSE");

    return 0;
}

void cargarRandom(Pila * p)
{
    srand(time(NULL));

    int i = 0, cantElementos = 0;

    printf("Cuantos elementos desea agregar (0 - 9) ");
    scanf("%d", &cantElementos);

    if(cantElementos <= 9)
    {
        for(i=0; i<cantElementos; i++)
        {
            apilar(p, rand()%9 + 1);
        }
    }
    else
    {
        printf("El numero ingresado no es valido\n");
        system("PAUSE");
        system("cls");

        cargarRandom(p);
    }
}

void ordenarPila(Pila origen, Pila * destino)
{
    Pila aux, menor;
    inicpila(&aux);
    inicpila(&menor);

    while(!pilavacia(&origen))
    {
        apilar(&menor, desapilar(&origen));

        while (!pilavacia(&origen))
        {
            if(tope(&origen) < tope(&menor))
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

int mostrarElemetosComoEntero(Pila p)
{
    int suma = 0, mult = 1;

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        apilar(&aux, desapilar(&p));
    }

    while(!pilavacia(&aux))
    {
        suma = suma + tope(&aux) * mult;
        apilar(&p, desapilar(&aux));
        mult = mult * 10;
    }

    return suma;
}
