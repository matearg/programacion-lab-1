#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cargarArrayRandom(int a[], int cantElementos);
void mostrarArray(int a[], int validos);
int posMenorArray(int a[], int validos, int pos);
void ordenarSeleccion(int a[], int validos);
void intercambioPos(int *a, int *b);
void ordenarInsercion(int a[], int validos);
void insertar(int a[], int u, int dato);

int main()
{
    int arreglo[10];
    int validos = 0;
    int otroArrelgo[10];
    int otroValidos = 0;

    validos = cargarArrayRandom(arreglo, 10);

    printf("Arreglo luego de carga random:\n");
    mostrarArray(arreglo, validos);

    ordenarSeleccion(arreglo, validos);
    printf("\n\nArreglo luego de ordenacion por seleccion:\n");
    mostrarArray(arreglo, validos);

    otroValidos = cargarArrayRandom(otroArrelgo, 10);

    printf("\n\nOtro arreglo luego de carga random:\n");
    mostrarArray(otroArrelgo, otroValidos);

    ordenarInsercion(otroArrelgo, otroValidos);
    printf("\n\nArreglo luego de ordenacion por insercion:\n");
    mostrarArray(otroArrelgo, otroValidos);

    return 0;
}

int cargarArrayRandom(int a[], int cantElementos)
{
    srand(time(NULL));

    int i;

    for(i = 0; i < cantElementos; i++)
    {
        a[i] = rand()%101;
    }

    return i;
}

void mostrarArray(int a[], int validos)
{
    int i;

    for(i = 0; i < validos; i++)
    {
        printf("%d| ", a[i]);
    }
}

int posMenorArray(int a[], int validos, int pos)
{
    int i = 0, menor = 0, posMenor = 0;

    menor = a[pos];
    posMenor = pos;

    for(i = pos + 1; i < validos; i++)
    {
        if(a[i] < menor)
        {
            menor = a[i];
            posMenor = i;
        }
    }

    return posMenor;
}

void intercambioPos(int *a, int *b)
{
    int aux = 0;

    aux = *a;
    *a = *b;
    *b = aux;
}
void ordenarSeleccion(int a[], int validos)
{
    int i = 0, posMenor;

    for(i = 0; i < validos - 1; i++)
    {
        posMenor = posMenorArray(a, validos, i);
        intercambioPos(&a[posMenor], &a[i]);
    }
}

void ordenarInsercion(int a[], int validos)
{
    int i = 0;

    for(i = 0; i < validos - 1; i++)
    {
        insertar(a, i, a[i+1]);
    }
}
 void insertar(int a[], int u, int dato)
{
    int i = u;
    while(i >= 0 && dato < a[i])
    {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = dato;
}
