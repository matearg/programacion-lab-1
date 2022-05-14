#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hacer una función que reciba como parámetro una matriz de números enteros
// y que cargue la misma con números aleatorios (sin intervención del usuario).
// La función debe cargar la matriz por completo.

void cargarMatrizRandom(int filas, int columnas, int m[filas][columnas]);
void mostrarMatriz(int filas, int columnas, int m[filas][columnas]);

int main()
{
    int matriz[4][4];

    cargarMatrizRandom(4, 4, matriz);

    printf("Matriz luego de cargar random:\n");
    mostrarMatriz(4, 4, matriz);

    printf("\n");
    system("PAUSE");
    system("cls");

    return 0;
}

void cargarMatrizRandom(int filas, int columnas, int m[filas][columnas])
{
    srand(time(NULL));

    int y, x;

    for(y = 0; y < filas; y++)
    {
        for(x = 0; x < columnas; x++)
        {
            m[y][x] = rand()%10;
        }
    }
}

void mostrarMatriz(int filas, int columnas, int m[filas][columnas])
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
