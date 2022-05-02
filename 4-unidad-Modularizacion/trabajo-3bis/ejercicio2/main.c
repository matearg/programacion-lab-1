#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Diseñe una función que reciba 3 números enteros
// y muestre el mayor y el menor.

void funcion(int a, int b, int c);

int main()
{
    srand(time(NULL));

    int num1 = 0, num2 = 0, num3 = 0;

    num1 = rand()%100 + 1;
    num2 = rand()%100 + 1;
    num3 = rand()%100 + 1;

    printf("Los numeros son %d, %d, %d\n", num1, num2, num3);

    funcion(num1, num2, num3);

    return 0;
}

void funcion(int a, int b, int c)
{
    int menor = 0, mayor;

    menor = a;

    mayor = a;

    if ((b < menor) & (b < c))
    {
        menor = b;
    }
    else if ((c < menor) & (c < b))
    {
        menor  = c;
    }
    else
    {
        menor = a;
    }

    if ((b > mayor) & (b > c))
    {
        mayor = b;
    }
    else if ((c > mayor) & (c > b))
    {
        mayor  = c;
    }
    else
    {
        mayor = a;
    }

    printf("El menor es %d y el mayor %d\n", menor, mayor);
}
