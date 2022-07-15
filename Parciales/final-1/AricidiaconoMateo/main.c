#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

#define LECTURA "rb"
#define LECTURA_ESCRITURA "r+b"
#define ANADIR "ab"
#define ARCHIVO_ARTICULOS "articulos.dat"

typedef struct
{
    int id;
    int codigo;
    int rubro; /// 1 Televisores / 2 Lavarropas / 3 Cocinas / 4 Calefactores
    char marca[30];
    char modelo[30];
    float precio;
} stArticulo;

typedef struct
{
    stArticulo * articulo;
    int cantArticulos;
} arrArticulos;

stArticulo *obternerArticulos(char rutaArchivo[], int *dim); /// 1
void listarArticulos(arrArticulos arregloArticulos[]); /// 2
int contarRegistros(char rutaArchivo[]); /// 4

int main()
{
    int validos = 0, cantRegistros = 0;
    arrArticulos arregloArticulos;

    arregloArticulos.articulo = obternerArticulos(ARCHIVO_ARTICULOS, &arregloArticulos.cantArticulos);

    validos = arregloArticulos.cantArticulos;
    printf("Hay %d articulos del rubro\n", validos);

    listarArticulos(&arregloArticulos);

    cantRegistros = contarRegistros(ARCHIVO_ARTICULOS);
    printf("\n\nHay %d registros en el archivo\n", cantRegistros);

    return 0;
}

stArticulo *obternerArticulos(char rutaArchivo[], int *dim) /// 1
{
    int i = 0;
    stArticulo articuloAux;
    stArticulo *arregloArticulos;

    FILE * archivoArticulos = NULL;

    archivoArticulos = fopen(rutaArchivo, LECTURA);

    if(archivoArticulos != NULL)
    {
        fseek(archivoArticulos, 0, SEEK_END);

        *dim = ftell(archivoArticulos) / sizeof(stArticulo);

        arregloArticulos = (stArticulo *)malloc((*dim) * sizeof(stArticulo));

        fseek(archivoArticulos, 0, SEEK_SET);

        fread(&articuloAux, sizeof(articuloAux), 1, archivoArticulos);

        i = 0;

        while (!feof(archivoArticulos))
        {
            arregloArticulos[i++] = articuloAux;
            fread(&articuloAux, sizeof(articuloAux), 1, archivoArticulos);
        }
    }
    else
    {
        printf("\nOcurrio un error al abrir el archivo\n");
        *dim = 0;
        arregloArticulos = (stArticulo *)malloc(sizeof(stArticulo));
    }

    return arregloArticulos;
}

void listarArticulos(arrArticulos arregloArticulos[]) /// 2
{
    int i = 0;

    for(i = 0; i < arregloArticulos->cantArticulos; i++)
    {
        printf("\n");
        printf("%d ", arregloArticulos->articulo[i].id);
        printf("%d ", arregloArticulos->articulo[i].codigo);
        printf("%d ", arregloArticulos->articulo[i].rubro);
        printf("%s ", arregloArticulos->articulo[i].marca);
        printf("%s ", arregloArticulos->articulo[i].modelo);
        printf("%.2f ", arregloArticulos->articulo[i].precio);
    }
}

int contarRegistros(char rutaArchivo[])
{
    int cant;
    FILE * archivoArticulos = NULL;
    archivoArticulos = fopen(ARCHIVO_ARTICULOS, LECTURA);

    if(archivoArticulos != NULL)
    {
        fseek(archivoArticulos, 0, SEEK_END);
        cant = ftell(archivoArticulos) / sizeof(stArticulo);
    }
    else
    {
        printf("\nOcurrio un error al abrir el archivo\n");
    }

    return cant;
}
