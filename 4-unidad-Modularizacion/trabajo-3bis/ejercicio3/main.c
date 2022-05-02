#include <stdio.h>
#include <stdlib.h>

// Diseñe una función que reciba un número entero N y realice la
// suma de los números enteros positivos menores que N y lo retorne.
// N es un dato ingresado por el usuario en el main.

int sumaGaussiana(int n);

int main()
{
    int num;

    printf("Ingrese un numero ");
    scanf("%d", &num);

    printf("La suma de los anteriores de %d es %d\n", num, sumaGaussiana(num));

    return 0;
}

int sumaGaussiana(int n)
{
    int resultado = 0;

    resultado = (n*(n+1))/2;

    return resultado;
}
