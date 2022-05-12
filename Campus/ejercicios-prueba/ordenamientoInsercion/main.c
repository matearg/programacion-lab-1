#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_E 10

int cargarArray(int a[]);
void mostrarArray(int a[], int validos);
void ordenarArray(int a[], int validos);

int main() {

  int arreglo[CANT_E], validos;

  validos = cargarArray(arreglo);

  system("cls");

  printf("Arrelgo luego de cargar:\n");
  mostrarArray(arreglo, validos);

  ordenarArray(arreglo, validos);

  printf("\n\nArrelgo luego de ordenar:\n");
  mostrarArray(arreglo, validos);

  printf("\n\n");
  system("PAUSE");
  system("cls");

  return 0;
}

int cargarArray(int a[]) {

  srand(time(NULL));

  int i;

  for (i = 0; i < CANT_E; i++) {
    a[i] = rand() % 101;
  }

  return i;
}

void mostrarArray(int a[], int validos) {

  int i;

  for (i = 0; i < validos; i++) {

    printf("| %d ", a[i]);
  }
}

void ordenarArray(int a[], int validos) {

  int i, j, menor;

  for (i = 1; i < validos; i++) {

    menor = a[i];

    j = i;

    while (j > 0 && a[j - 1] > menor) {

      a[j] = a[j - 1];

      j--;
    }

    a[j] = menor;
  }
}
