#include <stdio.h>
#include <stdlib.h>

// Leer 10 n�meros e imprimir solamente los n�meros positivos

int main()
{
	int num = 0, cantNum = 0;

	do
	{
		printf("Introduce un numero entero: ");
		scanf("%i", &num);

		cantNum = cantNum + 1;

		if (num > 0)
		{
			printf("El numero %i es positivo\n", num);
		}
		else
		{
			continue;
		}
	} while (cantNum < 10);

	return 0;
}
