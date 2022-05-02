#include <stdio.h>
#include <stdlib.h>

// Un obrero necesita calcular su salario semanal,
// el cual se obtiene de la sig. manera: Si trabaja 40 horas
// o menos se le paga $300 por hora Si trabaja más de 40 horas
// se le paga $300 por cada una de las primeras 40 horas y
// $400 por cada hora extra.

int main()
{
    int horas = 0;
    float salario = 0;

    printf("Ingrese las horas trabajadas: ");
    scanf("%i", &horas);

    if (horas <= 40)
    {
        salario = horas * 300;
    }
    else
    {
        salario = (40 * 300) + ((horas - 40) * 400);
    }

    printf("El salario es: $%.2f\n", salario);

    return 0;
}
