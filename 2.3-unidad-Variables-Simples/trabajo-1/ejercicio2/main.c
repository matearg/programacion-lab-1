#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

// Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
// Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.

int main() {
  char condicion;
  Pila origen, destino;

  inicpila(&origen);
  inicpila(&destino);

  printf("Cargar pila origen \n");
  do {
    leer(&origen);

    printf("Desea continuar s/n ---> ");
    fflush(stdin);
    scanf("%c", &condicion);
  } while (condicion == 's');

  printf("Origen");
  mostrar(&origen);

  while (!pilavacia(&origen)) {
    apilar(&destino, desapilar(&origen));
  }

  printf("Destino");
  mostrar(&destino);

  return 0;
}
