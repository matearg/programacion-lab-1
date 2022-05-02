#include <stdio.h>
#include <stdlib.h>

// Desarrollar una función que muestre la tabla de multiplicar
// de un número entero recibido por parámetro.

void tablaMult(int n);

int main()
{
    int num = 0;

    printf("Ingrese un numero ");
    scanf("%d", &num);

    tablaMult(num);

    return 0;
}

void tablaMult(int n)
{
    int i = 0, mult = 0, num = 0;

    printf("La tabla de productos de %d es ", n);

    for(i=0;i<=10;i++)
    {
        mult = n * i;
        printf("%d ", mult);
    }
}
