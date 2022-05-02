#include <stdio.h>
#include <stdlib.h>

// Desarrolle un algoritmo que lea dos números y
// los imprima en forma ascendente

int main()
{
    int n1 = 0, n2 = 0;

    printf("Introduzca el primer numero: ");
    scanf("%i", &n1);

    printf("Introduzca el segundo numero: ");
    scanf("%i", &n2);

    if (n1 < n2)
    {
        printf("%i %i", n1, n2);
    }
    else
    {
        printf("%i %i", n2, n1);
    }

    return 0;
}
