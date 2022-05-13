#include <stdio.h>
#include <stdlib.h>

// Hacer una función que reciba como parámetro una matriz de números
// enteros y permita que el usuario ingrese valores al mismo por teclado.
// La función debe cargar la matriz por completo.

void mostrarMatriz(int columnas, int filas, int m[columnas][filas]);
void cargarMatrizUsr(int columnas, int filas, int m[columnas][filas]);

int main()
{
    int matriz[3][3];

    cargarMatrizUsr(3, 3, matriz);

    printf("Matriz luego de carga:\n");
    mostrarMatriz(3, 3, matriz);

    return 0;
}

void mostrarMatriz(int columnas, int filas, int m[columnas][filas])
{
    int y, x;

    for(y = 0; y < filas; y++)
    {
        for(x = 0; x < columnas; x++)
        {
            printf("[%d]", m[y][x]);
        }
        printf("\n");
    }
}

void cargarMatrizUsr(int columnas, int filas, int m[columnas][filas])
{
    int y, x;

    for(y = 0; y < filas; y++)
    {
        for(x = 0; x < columnas; x++)
        {
            printf("Ingrese un valor a la fila %d columna %d ", y, x);
            scanf("%d", &m[y][x]);
        }
    }
}
