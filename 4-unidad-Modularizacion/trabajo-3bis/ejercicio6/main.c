#include <stdio.h>
#include <stdlib.h>

// Realizar una función que reciba un numero positivo entero
// por parametro por referencia, y cambie su signo a negativo.

int pasarNegativo(int a);

int main()
{
    int num;

    printf("Ingresa un numero positivo ");
    scanf("%d", &num);

    printf("Numero negativo %d", pasarNegativo(num));

    return 0;
}

int pasarNegativo(int a)
{
    a = a * -1;

    return a;
}
