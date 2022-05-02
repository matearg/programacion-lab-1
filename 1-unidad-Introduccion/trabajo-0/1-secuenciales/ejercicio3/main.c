#include <stdio.h>
#include <stdlib.h>

// Un maestro desea saber qué porcentaje de hombres y que
// porcentaje de mujeres hay en un grupo de estudiantes.

int main()
{
    int hombres = 0, mujeres = 0, total = 0;
    float porcentaje_hombres = 0, porcentaje_mujeres = 0;

    printf("Ingrese la cantidad de hombres: ");
    scanf("%d", &hombres);
    printf("Ingrese la cantidad de mujeres: ");
    scanf("%d", &mujeres);

    total = hombres + mujeres;

    porcentaje_hombres = (float)hombres / total * 100;

    porcentaje_mujeres = (float)mujeres / total * 100;

    printf("El porcentaje de hombres es: %.2f\n", porcentaje_hombres);
    printf("El porcentaje de mujeres es: %.2f\n", porcentaje_mujeres);

    return 0;
}
