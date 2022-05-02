#include <stdio.h>
#include <stdlib.h>

// Una tienda ofrece un descuento del 15% sobre el total
// de la compra y un cliente desea saber cuánto deberá
// pagar finalmente por su compra.

int main()
{
    int precioInicial = 0;
    float precioFinal = 0;
    float descuento = 0;

    printf("Ingrese el precio inicial: ");
    scanf("%d", &precioInicial);

    descuento = (float)(precioInicial * 0.15);
    precioFinal = precioInicial - descuento;

    printf("El precio final es: %.2f", precioFinal);

    return 0;
}
