#include <stdio.h>
#include <stdlib.h>

// Leer 10 numeros y obtener su cubo y su cuarta

int main()
{
	int num = 0, cantNum = 0, cubo = 0, cuarta = 0;

	do
	{
		printf("Introduce un numero entero: ");
		scanf("%i", &num);

		cubo = num * num * num;
		cuarta = cubo * num;

		printf("El cubo de %i es %i\n", num, cubo);
		printf("La cuarta de %i es %i\n", num, cuarta);

		cantNum = cantNum + 1;
	} while (cantNum < 10);

	return 0;
}
