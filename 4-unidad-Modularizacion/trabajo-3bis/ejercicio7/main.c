#include <stdio.h>
#include <stdlib.h>

// Realizar una funcion que reciba dos numeros enteros por parametro
// por referencia y cargue sus valores el usuario dentro de la funcion.

int sumarDosNumeros(int a, int b);

int main()
{
    int num1, num2;

    printf("Ingrese un numero ");
    scanf("%d", &num1);

    printf("Ingrese un numero ");
    scanf("%d", &num2);

    printf("La suma de %d y %d es %d\n", num1, num2, sumarDosNumeros(num1, num2));

    return 0;
}

int sumarDosNumeros(int a, int b)
{
    int resultado;

    resultado = a + b;

    return resultado;
}
