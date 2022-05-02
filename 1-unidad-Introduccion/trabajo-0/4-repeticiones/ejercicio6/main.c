#include <stdio.h>
#include <stdlib.h>

// Calcular e imprimir la tabla de multiplicar de un número cualquiera.
// Imprimir el multiplicando, el multiplicador y el producto

int main()
{
    int num = 0, multiplicador = 0, producto = 0;
    printf("Introduce un numero: ");
    scanf("%d", &num);
    for (multiplicador = 0; multiplicador <= 10; multiplicador++)
    {
        producto = num * multiplicador;
        printf("%d x %d = %d\n", num, multiplicador, producto);
    }
    return 0;
}
