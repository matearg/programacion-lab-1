#include <stdio.h>
#include <stdlib.h>

// Leer tres números diferentes e imprimir el número mayor de los tres.

int main()
{
    int n1 = 0, n2 = 0, n3 = 0;

    printf("Introduzca el primer numero: ");
    scanf("%i", &n1);

    printf("Introduzca el segundo numero: ");
    scanf("%i", &n2);

    printf("Introduzca el tercer numero: ");
    scanf("%i", &n3);

    if (n1 > n2 && n1 > n3)
    {
        printf("%i es el numero mas grande", n1);
    }
    else if (n2 > n1 && n2 > n3)
    {
        printf("%i es el numero mas grande", n2);
    }
    else
    {
        printf("%i es el numero mas grande", n3);
    }

    return 0;
}
