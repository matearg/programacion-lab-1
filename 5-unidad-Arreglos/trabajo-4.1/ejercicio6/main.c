#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hacer una función que determine si un elemento se encuentra dentro de una
// matriz de números enteros. La función recibe la matriz y el dato a buscar

void cargarMatrizRandom(int filas, int columnas, int m[filas][columnas]);
void mostrarMatriz(int filas, int columnas, int m[filas][columnas]);
void buscarMatriz(int filas, int columnas, int m[filas][columnas], int dato);

int main()
{
    int matriz[3][3], datoABuscar;

    system("cls");

    cargarMatrizRandom(3, 3, matriz);

    printf("Matriz luego de cargar:\n");
    mostrarMatriz(3, 3, matriz);

    printf("\nIngrese un dato a buscar: ");
    scanf("%d", &datoABuscar);

    printf("\n");
    buscarMatriz(3, 3, matriz, datoABuscar);

    printf("\n");
    system("PAUSE");
    system("cls");

    return 0;
}

void cargarMatrizRandom(int filas, int columnas, int m[filas][columnas])
{
    srand(time(NULL));

    int i, j;

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            m[i][j] = rand()%10;
        }
    }
}

void mostrarMatriz(int filas, int columnas, int m[filas][columnas])
{
    int i, j;

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            printf("[%d]", m[i][j]);
        }
        printf("\n");
    }
}

void buscarMatriz(int filas, int columnas, int m[filas][columnas], int dato)
{
    int i, j, aEval = 0;

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            aEval = m[i][j];

            if(aEval == dato)
            {
                printf("[SI]");
            }
            else
            {
                printf("[NO]");
            }
        }
        printf("\n");
    }
}
