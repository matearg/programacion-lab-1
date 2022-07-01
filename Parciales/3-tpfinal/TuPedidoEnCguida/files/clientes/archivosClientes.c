#include <stdlib.h>
#include <stdio.h>

#include "../common/mensajes.h"
#include "archivosClientes.h"

#define MODO_LECTURA "rb"
#define MODO_ANADIR "ab"
#define MODO_LEC_ESCRIT "r+b"

void cargarClientesArchivo(char rutaArchivo[], stCliente arregloClientes[], int dim)
{
    FILE * archivo = NULL;

    archivo = fopen(rutaArchivo, MODO_ANADIR);
    if(archivo != NULL)
    {
        fwrite(arregloClientes, sizeof(stCliente), dim, archivo);
        fclose(archivo);
    }
    else
    {
        printfError("Ocurrio un error al querer abrir el archivo.");
    }
}

stCliente * obtenerClientes(char rutaArchivo[], int * cantClientes)
{
    int i;
    stCliente clienteAux;
    stCliente *arregloClientes;

    FILE * archivoClientes = NULL;
    archivoClientes = fopen(rutaArchivo, MODO_LECTURA);

    if(archivoClientes != NULL)
    {
        fseek(archivoClientes, 0, SEEK_END); /* Posiciona el cursor al final del archivo */
        *cantClientes = ftell(archivoClientes) / sizeof(stCliente); /* # de clientes almacenados en el archivo. (# de registros) */
        arregloClientes = (stCliente *)malloc((*cantClientes) * sizeof(stCliente));/* Se reserva memoria para todos los clientes almacenados en el archivo */

        /* Se recorre el archivo secuencialmente */
        fseek(archivoClientes, 0, SEEK_SET); /* Posiciona el cursor al principio del archivo */
        fread(&clienteAux, sizeof(stCliente), 1, archivoClientes);
        i = 0;
        while (!feof(archivoClientes))
        {
            arregloClientes[i++] = clienteAux;
            fread(&clienteAux, sizeof(stCliente), 1, archivoClientes);
        }
    }
    else
    {
        printfError("Ocurrio un error al querer abrir el archivo.");

        *cantClientes = 0;
        arregloClientes = (stCliente *)malloc(sizeof(stCliente));
    }

    return arregloClientes;
}

int insertarCliente(char rutaArchivo[], stCliente cliente)
{
    FILE *archivoClientes;
    int insercion = 0;

    /* Abre el archivo para agregar datos al final */
    archivoClientes = fopen(rutaArchivo, MODO_ANADIR);	/* Añade datos al final. Si el archivo no existe, es creado */

    if(archivoClientes != NULL)
    {
        fwrite(&cliente, sizeof(cliente), 1, archivoClientes);
        insercion = 1;
        fclose(archivoClientes);
    }
    else
    {
        printfError("Ocurrio un error al intentar abrir el archivo.");
    }

    return insercion;
}

int desactivarCliente(char rutaArchivo[], int idCliente)
{
    stCliente clienteAux;
    int elimina = 0;

    FILE *archivoClientes;                             /* Abre el archivo para leer */
    archivoClientes = fopen(rutaArchivo, MODO_LEC_ESCRIT);	/* Modo lectura/escritura. Si el archivo no existe, es creado */

    if(archivoClientes != NULL)
    {
        fread(&clienteAux, sizeof(clienteAux), 1, archivoClientes);
        while (!feof(archivoClientes))
        {

            if (clienteAux.idCliente == idCliente)
            {
                fseek(archivoClientes, ftell(archivoClientes) - sizeof(clienteAux), SEEK_SET); /* El puntero se encuentra al final del elemento entonces debemos hacer que retroceda*/

                clienteAux.activo = CLIENTE_DESACTIVADO;
                fwrite(&clienteAux, sizeof(clienteAux), 1, archivoClientes);
                elimina = 1;

                break;
            }
            fread(&clienteAux, sizeof(clienteAux), 1, archivoClientes);
        }

        /* Cierra el archivo */
        fclose(archivoClientes);
    }
    else
    {
        printfError("Ocurrio un error al querer abrir el archivo.");
    }

    return elimina;
}

int modificarCliente(char rutaArchivo[], stCliente clienteModificado)
{
    int modifica = 0;
    stCliente clienteAux;

    FILE *archivoClientes;
    archivoClientes = fopen(rutaArchivo, MODO_LEC_ESCRIT); /* Abre el archivo para lectura/escritura */

    if(archivoClientes != NULL)
    {
        fread(&clienteAux, sizeof(clienteAux), 1, archivoClientes);
        while (!feof(archivoClientes))
        {

            if (clienteAux.idCliente == clienteModificado.idCliente)
            {

                fseek(archivoClientes, ftell(archivoClientes) - sizeof(clienteModificado), SEEK_SET); /* El puntero se encuentra al final del elemento entonces debemos hacer que retroceda*/
                fwrite(&clienteModificado, sizeof(clienteModificado), 1, archivoClientes);
                modifica = 1;
                break;
            }
            fread(&clienteAux, sizeof(clienteAux), 1, archivoClientes);
        }

        fclose(archivoClientes);
    }
    else
    {
        printfError("Ocurrio un error al querer abrir el archivo.");
    }

    return modifica;
}
