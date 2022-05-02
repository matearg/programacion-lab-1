#include <stdio.h>
#include <stdlib.h>

int sumar(int a, int b)
{
    int resultado = 0;

    resultado = a + b;

    return resultado;
}

int main()
{
    int n1, n2, rta;
    printf("Hola funciones!!\n");
    printf("Ingrese dos valores enteros: \n");
    scanf("%d", &n1);
    scanf("%d", &n2);

    rta = sumar(n1, n2);

    // Una forma de mostrar el valor retornado es guardarlo en una variable
    printf("\nLa respuesta es %d", rta);

    // Otra forma es llamar a la funcion desde un printf
    printf("\nLa respuesta es %d", sumar(n1, n2));

    return 0;
}
