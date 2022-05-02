#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cantTemp = 0, condicion = 1;
    float temp, tempMax = 0, tempMin = 0, sumaTemp = 0, tempPromedio = 0;

    do
    {
        printf("Ingrese una temperatura: ");
        scanf("%f", &temp);

        if (cantTemp == 0)
        {
            tempMax = temp;
            tempMin = temp;
        }else if (temp > tempMax) {
            tempMax = temp;
        }else if (temp < tempMin){
            tempMin = temp;
        }

        sumaTemp = sumaTemp + temp;

        cantTemp++;

        printf("Desea ingresar una nueva temperatura (SI = 1 / NO = 0): ");
        scanf("%d", &condicion);

    } while (condicion == 1);

    tempPromedio = sumaTemp / cantTemp;

    printf("La temperatura promedio es %.2f, la temperatura maxima es %.2f y la temperatura minima es %.2f", tempPromedio, tempMax, tempMin);

    return 0;
}
