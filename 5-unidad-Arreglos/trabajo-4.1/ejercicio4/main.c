#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hacer una función tipo int que sume el contenido
// total de una matriz de números enteros

void cargarMatrizRandom(int filas, int columnas, int m[filas][columnas]);
void mostrarMatriz(int filas, int columnas, int m[filas][columnas]);
int sumMatriz(int filas, int columnas, int m[filas][columnas]);

int main()
{
    int matriz[3][3], sumM = 0;

    system("cls");

    cargarMatrizRandom(3, 3, matriz);

    printf("Matriz luego de carga:\n");
    mostrarMatriz(3, 3, matriz);

    sumM = sumMatriz(3, 3, matriz);

    printf("\nLa sumatoria de los elementos de la matriz es %d\n", sumM);

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


int sumMatriz(int filas, int columnas, int m[filas][columnas])
{
    int y, x, sum = 0;

    for(y = 0; y < filas; y++)
    {
        for(x = 0; x < columnas; x++)
        {
            sum += m[y][x];
        }
    }

    return sum;
}
