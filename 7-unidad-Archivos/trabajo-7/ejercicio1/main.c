#include <stdio.h>
#include <stdlib.h>

/* 1. Hacer una función que agregue un elemento al final de un archivo. */
/* 2. Hacer una función que muestre por pantalla el contenido de un archivo. */
/* 3. Hacer una función que retorne la cantidad de registros que contiene un archivo. */

void menu(char archivo[]);
void agregarElemento(char archivo[]);
void mostrarArchivo(char archivo[]);
int cantidadRegistros(char archivo[]);

int main()
{
    menu("archivo.dat");
    return 0;
}

void menu(char archivo[])
{
    int opcion;

    do
    {
        system("cls");
        printf(
            "1 Agregar elemento\n"
            "2 Mostrar archivo\n"
            "3 Cantidad de registros\n"
            "0 Salir\n\n"
            "Introduzca una opcion: "
        );
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarElemento(archivo);
            break;
        case 2:
            mostrarArchivo(archivo);
            break;
        case 3:
            cantidadRegistros(archivo);
            break;
        }
    }
    while(opcion != 0);
}

void agregarElemento(char archivo[])
{
    int e;
    FILE *archi;
    char condicion;

    archi = fopen(archivo, "ab");

    if(archi != NULL)
    {
        do
        {
            system("cls");

            printf("Ingrese un numero: ");
            fflush(stdin);
            scanf("%d", &e);

            fwrite(&e, sizeof(e), 1, archi);

            printf("Desea agregar otro? s/n: ");
            fflush(stdin);
            scanf("%c", &condicion);
        }
        while (condicion == 's');

        fclose(archi);
    }
    else
    {
        printf("Error en el archivo. ");
    }

    system("pause");
}

void mostrarArchivo(char archivo[])
{
    int e;
    FILE *archi;

    archi = fopen(archivo, "rb");

    system("cls");

    if(archi != NULL)
    {
        while(fread(&e, sizeof(e), 1, archi) > 0)
        {
            printf("%d\n", e);
        }
        fclose(archi);
    }
    else
    {
        printf("Error en el archivo. ");
    }

    system("pause");
}

int cantidadRegistros(char archivo[])
{
    int e;
    FILE * archi;
    int i = 0;

    archi = fopen(archivo, "rb");

    system("cls");

    if(archi != NULL)
    {
        while(fread(&e, sizeof(e), 1, archi) > 0)
        {
            i++;
        }
        fclose(archi);
    }
    else
    {
        printf("Error en el archivo. ");
    }

    printf("El archivo tiene %d registros.\n\n", i);
    system("pause");

    return i;
}
