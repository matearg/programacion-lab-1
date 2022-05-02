#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// Comparar la cantidad de elementos de las pilas A y B.
// Mostrar por pantalla el resultado

int main()
{
    char condicion, condicion1;
    Pila pilaA, pilaB, aux1, aux2;

    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&aux1);
    inicpila(&aux2);

    printf("Cargando pilaA \n");
    do {

        leer(&pilaA);

        printf("Desea continuar s/n ---> ");
        fflush(stdin);
        scanf("%c", &condicion);

    } while (condicion == 's');

    printf("Cargando pilaB \n");
    do {

        leer(&pilaB);

        printf("Desea continuar s/n ---> ");
        fflush(stdin);
        scanf("%c", &condicion1);

    } while (condicion1 == 's');

    while(!pilavacia(&pilaA) && !pilavacia(&pilaB))
    {
        apilar(&aux1, desapilar(&pilaA));
        apilar(&aux2, desapilar(&pilaB));
    }

    if (pilavacia(&pilaA))
    {
        printf("La pilaA tiene menos elementos \n");
    }
    else if (pilavacia(&pilaA) && pilavacia(&pilaB))
    {
        printf("Las pilas tienen la misma cantidad de elementos \n");
    }
    else
    {
        printf("La pilaB tiene menos elementos \n");
    }

    while(!pilavacia(&aux1))
    {
        apilar(&pilaA, desapilar(&aux1));
    }
    printf("Pila A");
    mostrar(&pilaA);

    while(!pilavacia(&aux2))
    {
        apilar(&pilaB, desapilar(&aux2));
    }
    printf("Pila B");
    mostrar(&pilaB);

    return 0;
}
