#include <stdio.h>
#include <stdlib.h>

// Hacer una funci�n que reciba como par�metro un arreglo de n�meros enteros
// y permita que el usuario ingrese valores al mismo por teclado.
// La funci�n debe retornar la cantidad de elementos cargados en el
// arreglo (o pueden utilizar como puntero validos).

int cantElementos(int a[]);

int main()
{
    int arreglo[100];

    printf("\n\nEl arreglo contiene %d elementos\n\n", cantElementos(arreglo));

    system("PAUSE");

    return 0;
}

int cantElementos(int a[])
{
    int /*i = 0,*/validos = 0;
    char condicion;

    do
    {
        printf("Ingrese un dato al arreglo ");
        scanf("%d", &a[validos]);
        validos++;

        printf("\nQuiere agregar otro dato? s/n ");
        fflush(stdin);
        scanf("%c", &condicion);
    }
    while (condicion == 's');

    // for(i=0;i<validos;i++)
    // {
    //     printf("%d | ", &a);
    // }

    return validos;
}
