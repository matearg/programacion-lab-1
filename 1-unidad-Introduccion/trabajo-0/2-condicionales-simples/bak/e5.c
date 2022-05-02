#include <stdio.h>
#include <stdlib.h>

// Hacer un algoritmo que calcule el total a pagar por la compra de camisas.
// Si se compran tres camisas o más se aplica un descuento del 20%
// sobre el total de la compra y si son menos de tres camisas un descuento del 10%

int main()
{
    int numCamisas = 0;
    float precioPorCamisa = 0, precioTotal = 0, precioNuevo = 0;

    printf("Introduzca la cantidad de camisas: ");
    scanf("%i", &numCamisas);

    printf("Introduzca el precio unitario de las camisas: $");
    scanf("%f", &precioPorCamisa);

    precioTotal = precioPorCamisa * numCamisas;

    if (numCamisas < 3)
    {
        precioNuevo = precioTotal * 0.90;
        printf("El precio de las camisas sera $%.2f", precioNuevo);
    }
    else
    {
        precioNuevo = precioTotal * 0.80;
        printf("El precio de las camisas sera $%.2f", precioNuevo);
    }

    return 0;
}
