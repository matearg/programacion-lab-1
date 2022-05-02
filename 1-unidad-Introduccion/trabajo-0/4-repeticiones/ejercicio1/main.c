#include <stdio.h>
#include <stdlib.h>

// Calcular el promedio de un alumno que tiene 7
// calificaciones en la materia de Programación 1

int main()
{
    int cantNotas = 0;
    float calificacion, sumaNotas = 0, notaFinal = 0;

    do
    {
        printf("\nIntroduce una calificacion: ");
        scanf("%f", &calificacion);

        cantNotas = cantNotas + 1;
        sumaNotas = sumaNotas + calificacion;

        printf("Cantidad de notas ingresadas: %i\n", cantNotas);
    } while (cantNotas < 7);

    notaFinal = sumaNotas / cantNotas;

    printf("\nEl promedio de notas es: %.2f", notaFinal);

    return 0;
}
