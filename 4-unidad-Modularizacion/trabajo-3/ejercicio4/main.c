#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

// Hacer una función que encuentre el menor elemento de una pila y
// lo retorna. La misma debe eliminar ese dato de la pila.

void cargarRandom(Pila * p);
int buscarMenor(Pila * p);

int main()
{
    Pila dada;
    inicpila(&dada);

    cargarRandom(&dada);

    puts("Pila dada luego de carga random");
    mostrar(&dada);

    printf("Menor elemento %d\n", buscarMenor(&dada));

    return 0;
}

void cargarRandom(Pila * p)
{
    srand(time(NULL));

    int i = 0, cantElementos;

    printf("Cuantos elementos quiere ingresar: ");
    scanf("%d", &cantElementos);

    for (i = 0; i<cantElementos; i++)
    {
        apilar(p, rand()%100 + 1);
    }
}

int buscarMenor(Pila * p)
{
    Pila aux, menor;
    inicpila(&aux);
    inicpila(&menor);

    if(!pilavacia(p))
    {
        apilar(&menor, desapilar(p));

        while(!pilavacia(p))
        {
            if (tope(p) < tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(p));
            }
            else
            {
                apilar(&aux, desapilar(p));
            }
        }
        while(!pilavacia(&aux))
        {
            apilar(p, desapilar(&aux));
        }
    }

    return tope(&menor);
}
