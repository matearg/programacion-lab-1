#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int num, potencia;
    char condicion = 's';

    do {
        system("cls");

        printf("Ingrese un numero ");
        fflush(stdin);
        scanf("%d", &num);

        printf("Elevar %d a ", num);
        fflush(stdin);
        scanf("%d", &potencia);

        printf("%f\n", pow((double)num, (double)potencia));

        printf("Desea continuar? s/n\n");
        fflush(stdin);
        scanf("%c", &condicion);
    }
    while (condicion == 's');

    system("cls");
    printf("Adios!");

    return 0;
}
