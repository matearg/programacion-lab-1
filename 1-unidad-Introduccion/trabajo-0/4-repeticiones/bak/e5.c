#include <stdio.h>
#include <stdlib.h>

// Suponga que se tiene un conjunto de calificaciones de un grupo de 40 alumnos.
// Realizar un algoritmo para calcular la calificación promedio y
// la calificación más baja de todo el grupo

int main()
{
    int cantNotas = 0;
    float nota = 0, sumaNotas = 0, califPromedio = 0, califBaja = 0;

    printf("Introduzca una calificacion: ");
    scanf("%f", &nota);

    cantNotas = cantNotas + 1;
    sumaNotas = sumaNotas + nota;
    califBaja = califBaja + nota;

    do
    {
    	printf("Introduzca una calificacion: ");
    	scanf("%f", &nota);

    	cantNotas = cantNotas + 1;
	sumaNotas = sumaNotas + nota;

	if (nota < califBaja)
	{
	    califBaja = 0 + nota;
	}
	else
	{
	    continue;
	}
    } while (cantNotas < 40);

    califPromedio = sumaNotas / cantNotas;

    printf("El promedio de calificaciones del grupo es: %.2f\n", califPromedio);
    printf("La calificacion mas baja es: %.2f", califBaja);

    return 0;
}
