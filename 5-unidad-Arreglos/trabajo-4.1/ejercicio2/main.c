#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hacer una función que reciba como parámetro una matriz de números
// enteros y la muestre por pantalla (en formato matricial).

void cargarMatrizRandom(int filas, int columnas, int m[filas][columnas]);
void mostrarMatriz(int filas, int columnas, int m[filas][columnas]);

int main()
{
    int matriz[3][3];

    cargarMatrizRandom(3, 3, matriz);

    system("cls");

    printf("Matriz luego de carga random:\n");
    mostrarMatriz(3, 3, matriz);

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
