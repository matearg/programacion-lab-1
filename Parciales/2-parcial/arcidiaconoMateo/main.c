#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idMonotrib;
    long int cuit; // entre 2M y 10M
    char nombreYapellido[30];
} stMonotributista;

typedef struct
{
    int nroFactura;
    int idMonotrib;
    char tipoFactura; //A o B
    float montoTotal; // no + 500k && no < 0
} stFactura;

int cargarArregloMonotrib(stMonotributista lm[]); // 1
int cargarArregloFacturas(stMonotributista lm[], stFactura lf[], int dim); // 2
int buscarId(stMonotributista lm[], int idAbuscar, int dim); // 2c
void monotribAarchivo(stMonotributista lm[], char archivo[], int validos); // 3a
void facturaAarchivo(stFactura fc[], char archivo[], int validos); // 3b
void mostrarMonotrib(stMonotributista lm[], char archivo[]); // 4
void mostrarFactura(stFactura lf[], char archivo[]); // 4

int main()
{
    int validosMt = 0, validosFc = 0;
    stMonotributista listaMonotrib[100];
    stFactura listaFactura[100];

    validosMt = cargarArregloMonotrib(listaMonotrib);
    validosFc = cargarArregloFacturas(listaMonotrib, listaFactura, validosMt);

    printf("Se cargaron %d mt y %d fc", validosMt, validosFc);

    monotribAarchivo(listaMonotrib, "monotributistas.dat", validosMt);
    mostrarMonotrib(listaMonotrib, "monotributistas.dat");

    facturaAarchivo(listaFactura, "facturas.dat", validosFc);
    mostrarFactura(listaFactura, "facturas.dat");

    return 0;
}

int cargarArregloMonotrib(stMonotributista lm[])
{
    int i = 0, dim = 100;
    char condicion;

    do
    {
        system("cls");

        printf("Introduzca el id: ");
        fflush(stdin);
        scanf("%d", &lm[i].idMonotrib);

        printf("Introduzca el nombre y apellido: ");
        fflush(stdin);
        scanf("%s", lm[i].nombreYapellido);

        do
        {
            printf("Introduzca el cuit: ");
            fflush(stdin);
            scanf("%li", &lm[i].cuit);
        }
        while((lm[i].cuit < 2000000) && (lm[i].cuit > 10000000));

        printf("\nDesea agreagar otro? s/n: ");
        fflush(stdin);
        scanf("%c", &condicion);

        i++;
    }
    while(condicion == 's' && i < dim);

    return i;
}

int cargarArregloFacturas(stMonotributista lm[], stFactura lf[], int validos)
{
    int i = 0;
    int verifId = 0;
    char condicion;

    do
    {
        system("cls");

        printf("Introduzca el id del monotributista: ");
        fflush(stdin);
        scanf("%d", &lf[i].idMonotrib);

        verifId = buscarId(lm, lf[i].idMonotrib, validos);

        if (verifId != 0)
        {
            cargarArregloMonotrib(lm);
        }

        printf("\nIntroduzca el numero de la factura: ");
        fflush(stdin);
        scanf("%d", &lf[i].nroFactura);

        do
        {
            printf("\nIntroduzca el tipo de factura A/B: ");
            fflush(stdin);
            scanf("%c", &lf[i].tipoFactura);
        }
        while(lf[i].tipoFactura != 'A' && lf[i].tipoFactura != 'B');

        do
        {
            printf("\nIntroduzca el monto total: ");
            fflush(stdin);
            scanf("%f", &lf[i].montoTotal);
        }
        while(lf[i].montoTotal > 500000 && lf[i].montoTotal < 0);

        i++;

        printf("Desea agregar otra? s/n: ");
        fflush(stdin);
        scanf("%c", &condicion);
    }
    while(condicion == 's' && i < validos);

    return i;
}

int buscarId(stMonotributista lm[], int idAbuscar, int validos)
{
    int i = 0, flag = 1;

    for(i = 0; i < validos; i++)
    {
        if(lm[i].idMonotrib == idAbuscar)
        {
            flag = 0;
        }
    }

    return flag;
}

void monotribAarchivo(stMonotributista lm[], char archivo[], int validos)
{
    FILE *monotrib;
    int i = 0;

    monotrib = fopen(archivo, "ab");

    if(monotrib != NULL)
    {
        for(i = 0; i < validos; i++)
        {
            fwrite(&lm[i].idMonotrib, sizeof(stMonotributista), 1, monotrib);
            fwrite(&lm[i].nombreYapellido, sizeof(stMonotributista), 1, monotrib);
            fwrite(&lm[i].cuit, sizeof(stMonotributista), 1, monotrib);
        }
        fclose(monotrib);
    }
    else
    {
        printf("Error en el archivo.");
    }
}

void facturaAarchivo(stFactura fc[], char archivo[], int validos)
{
    FILE *facturas;
    int i = 0;

    facturas = fopen(archivo, "ab");

    if(facturas != NULL)
    {
        for(i = 0; i < validos; i++)
        {
            fwrite(&fc[i].idMonotrib, sizeof(stFactura), 1, facturas);
            fwrite(&fc[i].nroFactura, sizeof(stFactura), 1, facturas);
            fwrite(&fc[i].tipoFactura, sizeof(stFactura), 1, facturas);
            fwrite(&fc[i].montoTotal, sizeof(stFactura), 1, facturas);
        }
        fclose(facturas);
    }
    else
    {
        printf("Error en el archivo.");
    }
}

void mostrarMonotrib(stMonotributista lm[], char archivo[])
{
    FILE *archiv;
    int i = 0;

    archiv = fopen(archivo, "rb");

    if(archiv != NULL)
    {
        while(fread(&lm[i].idMonotrib, sizeof(stMonotributista), 1, archiv) > 0)
        {
            printf("\n%d ", lm[i].idMonotrib);
            printf("%s ", lm[i].nombreYapellido);
            printf("%ld ", lm[i].cuit);
            i++;
        }
    }
    else
    {
        printf("Error en el archivo.");
    }
}

void mostrarFactura(stFactura lf[], char archivo[])
{
    FILE *archiv;
    int i = 0;

    archiv = fopen(archivo, "rb");

    if(archiv != NULL)
    {
        while(fread(&lf[i].idMonotrib, sizeof(stFactura), 1, archiv) > 0)
        {
            printf("\n%d ", lf[i].idMonotrib);
            printf("%d ", lf[i].nroFactura);
            printf("%c ", lf[i].tipoFactura);
            printf("%f ", lf[i].montoTotal);
            i++;
        }
    }
    else
    {
        printf("Error en el archivo.");
    }
}
