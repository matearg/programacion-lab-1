#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cargarArreglo(int *a);
void ordenarArreglo(int *a, int val);
void mostrarArreglo(int *a, int val);

int main() {
  int *arreglo = (int *)malloc(sizeof(int) * 10);
  int validos = 0;

  validos = cargarArreglo(arreglo);

  system("cls");

  printf("\nArreglo luego de carga:\n");
  mostrarArreglo(arreglo, validos);

  printf("\nArreglo luego de ordenar:\n");
  ordenarArreglo(arreglo, validos);
  mostrarArreglo(arreglo, validos);

  printf("\n\n");

  system("PAUSE");
  system("cls");

  return 0;
}

void ordenarArreglo(int *a, int val) {
  int i = 0, j = 0, min = 0;

  for (i = 1; i < val; i++) {
    min = a[i];
    j = i;

    while (j > 0 && a[j - 1] > min) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = min;
  }
}

int cargarArreglo(int *a) {
  srand(time(NULL));

  int validos = 0, cantElementos = 0;

  printf("Cuantos elementos desea agregar ");
  scanf_s("%d", &cantElementos);

  if (cantElementos > 10) {
    a = (int *)realloc(a, sizeof(int) * cantElementos);
  }

  for (validos = 0; validos < cantElementos; ++validos) {
    a[validos] = rand() % 1001;
  }
  return validos;
}

void mostrarArreglo(int *a, int val) {
  int i = 0;

  for (i = 0; i < val; ++i) {
    printf("| %d ", a[i]);
  }
  printf("|\n");
}
