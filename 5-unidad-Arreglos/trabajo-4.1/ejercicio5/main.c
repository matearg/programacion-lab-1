#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hacer una función tipo float que calcule el promedio
// de una matriz de números enteros.

void cargarMatrizRandom(int filas, int columnas, int m[filas][columnas]);
void mostrarMatriz(int filas, int columnas, int m[filas][columnas]);
float promedioMatriz(int filas, int columnas, int m[filas][columnas]);

int main()
{
    int matriz[3][3];
    float promM = 0;

    system("cls");

    cargarMatrizRandom(3, 3, matriz);

    printf("Matriz luego de cargar:\n");
    mostrarMatriz(3, 3, matriz);

    promM = promedioMatriz(3, 3, matriz);

    printf("\nEl promedio de la matriz es %f\n", promM);

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

float promedioMatriz(int filas, int columnas, int m[filas][columnas])
{
    int y, x, sumM = 0;
    float promM = 0;

    for(y = 0; y < filas; y++)
    {
        for(x = 0; x < columnas; x++)
        {
            sumM += m[y][x];
        }
    }

    promM = (float)sumM / (y + x);

    return promM;
}
