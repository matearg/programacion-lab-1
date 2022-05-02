#include <stdio.h>
#include <stdlib.h>

// Pide un numero al usuario y muestra sus posibles divisores

int main()
{
    int num = 0, i = 0;
    char condicion;

    do
    {
        printf("Ingrese un numero: ");
        scanf("%d", &num);

        printf("Los divisores de %d son: ", num);

        for (i = 1; i <= num; i++)
        {
            if (num % i == 0)
            {
                printf("%d ", i);
            }
        }

        printf("\nDesea ingresar otro numero (s/n): ");
        fflush(stdin);
        scanf("%c", &condicion);
        if (condicion != 's' && condicion != 'n')
        {
            printf("El caracter ingresado es incorrecto\n");
        }

    }
    while (condicion == 's');

    return 0;
}
