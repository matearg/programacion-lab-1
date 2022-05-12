#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_E 20

int cargarArregloOrdenado(int a[]);
void mostrarArreglo(int a[], int validos);

int main()
{
    int arreglo[CANT_E], validos = 0;

    validos = cargarArregloOrdenado(arreglo);

    system("cls");

    printf("\nArreglo luego de carga:\n");
    mostrarArreglo(arreglo, validos);

    printf("\n\n");

    system("PAUSE");
    system("cls");

    return 0;
}

int cargarArregloOrdenado(int a[])
{
    srand(time(NULL));

    int i = 0, j = 0, menor = 0, validos = 0, cantElementos = 0;

    printf("Cuantos elementos desea agregar ");
    scanf("%d", &cantElementos);

    for(validos = 0; validos < cantElementos; validos++)
    {
        a[validos] = rand()%11;
    }

    for(i=1;i < validos; i++)
    {
        menor = a[i];
        j = i;

        while(j > 0 && a[j - 1] > menor)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = menor;
    }
}

void mostrarArreglo(int a[], int validos)
{
    int i = 0;

    for(i=0; i<validos; i++)
    {
        printf("| %d ", a[i]);
    }
}
