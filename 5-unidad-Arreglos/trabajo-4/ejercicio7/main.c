#include <stdio.h>
#include <stdlib.h>

#define CANT_E 20

// Realizar una función que inserte un carácter en un
// arreglo ordenado alfabéticamente,
// conservando el orden.

int cargarArreglo(char a[]);
void mostrarArrelgo(char a[], int validos);
void ordenarArrelgo(char a[], int validos);

int main()
{
    int validos = 0;
    char arreglo[CANT_E];

    validos = cargarArreglo(arreglo);

    printf("\nArrelgo luego de carga\n");
    mostrarArrelgo(arreglo, validos);

    ordenarArrelgo(arreglo, validos);

    printf("\n\nArrelgo luego de carga\n");
    mostrarArrelgo(arreglo, validos);

    printf("\n\n");
    system("PAUSE");

    return 0;
}

int cargarArreglo(char a[])
{
    char condicion = 's';
    int validos = 0;

    do
    {
        printf("Ingrese un caracter al arreglo ");
        fflush(stdin);
        scanf("%c", &a[validos]);

        validos++;

        printf("Desea continuar s/n ");
        fflush(stdin);
        scanf("%c", &condicion);
    }
    while (condicion == 's');

    return validos;
}

void mostrarArrelgo(char a[], int validos)
{
    int i = 0;

    for(i=0;i<validos;i++)
    {
        printf("| %c ", a[i]);
    }
}

void ordenarArrelgo(char a[], int validos)
{
    int i = 0, j = 0;
    char menor = 0;

    for (i = 1; i < validos; i++)
    {
		menor = a[i];

		j = i-1;

		while (j >= 0 && a[j] > menor){
            a[j+1] = a[j];

			j--;
		}
		a[j+1] = menor;
    }
}
