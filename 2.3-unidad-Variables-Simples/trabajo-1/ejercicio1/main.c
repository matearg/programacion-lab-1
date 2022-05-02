#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

// Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres
// primeros elementos que se encuentren en el tope a la pila AUX1 y los
// restantes a la pila AUX2, ambas pilas inicializadas.

int main() {
    char condicion;
    Pila dada, aux1, aux2;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    printf("Cargar en la pila dada 5 elementos \n");
    do {
        leer(&dada);
        printf("\n Desea continuar: s / n ---> ");
        fflush(stdin);
        scanf("%c", &condicion);
    } while (condicion == 's');
    printf("La pila dada contiene: ");

    mostrar(&dada);

    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));

    while (!pilavacia(&dada)) {
      apilar(&aux2, desapilar(&dada));
    }

    printf("AUX1");
    mostrar(&aux1);
    printf("AUX2");
    mostrar(&aux2);

    return 0;
}
