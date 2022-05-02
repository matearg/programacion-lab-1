#include <stdio.h>
#include <stdlib.h>

// Suponga que un individuo desea invertir su capital en un banco y desea saber
// cuánto dinero ganará después de un mes si el banco paga a razón de 2% mensual.

int main()
{
    float capital = 0, interes = 0.02, capLuegodeMes = 0;

    printf("Ingrese el capital a invertir: ");
    scanf("%f", &capital);

    capLuegodeMes = capital * interes;

    printf("El capital luego de un mes es: %.2f\n", capLuegodeMes);

    return 0;
}
