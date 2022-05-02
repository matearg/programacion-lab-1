#include <stdio.h>
#include <stdlib.h>

// Determinar si un alumno aprueba a reprueba un curso,
// sabiendo que aprobara si su promedio de tres
// calificaciones es mayor o igual a 7; reprueba en caso
// contrario.

int main()
{
    float nota1 = 0, nota2 = 0, nota3 = 0, promedio = 0;

    printf("Ingrese la primer nota: ");
    scanf("%f", &nota1);

    printf("Ingrese la seguda nota: ");
    scanf("%f", &nota2);

    printf("Ingrese la tercer nota: ");
    scanf("%f", &nota3);

    promedio = (nota1 + nota2 + nota3) / 3;

    if (promedio >= 7)
    {
        printf("El alumno aprueba el curso");
    }
    else
    {
        printf("El alumno reprueba el curso");
    }

    return 0;
}
