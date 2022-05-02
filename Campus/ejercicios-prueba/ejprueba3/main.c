#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

int main()
{
    Pila temperaturas;
    inicpila(&temperaturas);
    int temp;
    char condicion;

    leer(&temperaturas);

    do{
        printf("\n Ingrese una temperatura: ");
        scanf("%d", &temp);
        apilar(&temperaturas, temp);

        printf("\n ESC para salir o cualquier tecla para continuar ");
        condicion = getch();

        system("cls");
    }while(condicion != 27);

    printf("\n <<<<<<<<<<<<< Pila de Temperaturas >>>>>>>>>>>>>");
    mostrar(&temperaturas);

    return 0;
}
