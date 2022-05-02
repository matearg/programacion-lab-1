#include <stdio.h>
#include <stdlib.h>

// En un almacén se hace un 20% de descuento a los clientes cuya compra supere los $5000
// ¿Cuál será la cantidad que pagara una persona por su compra?

int main()
{
    float precio = 0, descuento = 0, precioNuevo = 0;

    printf("Introduzca el precio de su compra: $");
    scanf("%f", &precio);

    if (precio > 5000)
    {
        descuento = precio * 0.2;
        precioNuevo = precio - descuento;

        printf("El precio final es: $%.2f", precioNuevo);
    }
    else
    {
        printf("El precio final es: $%.2f", precio);
    }

    return 0;
}
