#include <stdio.h>
#include <stdlib.h>

// Leer 15 numeros negativos y convertirlos
// en positivos e imprimir dichos numeros

int main()
{
    int num = 0, cantNum = 0;

    do
    {
        printf("Introduce un numero negativo: ");
        scanf("%i", &num);

        if (num < 0)
        {
            num = -1 * num;
            cantNum = cantNum + 1;
            printf("El numero positivo seria %i\n", num);
        }
        else
        {
            cantNum = cantNum + 1;
            printf("El numero %i no es negativo\n", num);
        }
    } while (cantNum < 15);

    return 0;
}
