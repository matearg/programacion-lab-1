#include <stdio.h>
#include <stdlib.h>

#include "../common/mensajes.h"
#include "pedidos.h"
#include "archivosPedidos.h"

#define MODO_LECTURA "rb"
#define MODO_ANADIR "ab"
#define MODO_LEC_ESCRIT "r+b"

void cargarPedidosArchivo(char rutaArchivo[], stPedido arregloPedidos[], int dim)
{
    FILE * archivo = NULL;

    archivo = fopen(rutaArchivo, MODO_ANADIR);
    if(archivo != NULL)
    {
        fwrite(arregloPedidos, sizeof(stPedido), dim, archivo);
        fclose(archivo);
    }
    else
    {
        printfError("Ocurrio un error al querer abrir el archivo.");
    }
}

stPedido * obtenerPedidos(char rutaArchivo[], int * cantPedidos)
{
    int i;
    stPedido pedidoAux;
    stPedido *arregloPedidos;

    FILE * archivoPedidos = NULL;
    archivoPedidos = fopen(rutaArchivo, MODO_LECTURA);

    if(archivoPedidos != NULL)
    {
        fseek(archivoPedidos, 0, SEEK_END); /* Posiciona el cursor al final del archivo */
        *cantPedidos = ftell(archivoPedidos) / sizeof(stPedido); /* # de pedidos almacenados en el archivo. (# de registros) */
        arregloPedidos = (stPedido *)malloc((*cantPedidos) * sizeof(stPedido));/* Se reserva memoria para todos los pedidos almacenados en el archivo */

        /* Se recorre el archivo secuencialmente */
        fseek(archivoPedidos, 0, SEEK_SET); /* Posiciona el cursor al principio del archivo */
        fread(&pedidoAux, sizeof(pedidoAux), 1, archivoPedidos);
        i = 0;
        while (!feof(archivoPedidos))
        {
            arregloPedidos[i++] = pedidoAux;
            fread(&pedidoAux, sizeof(pedidoAux), 1, archivoPedidos);
        }
    }
    else
    {
        printfError("Ocurrio un error al querer abrir el archivo.");

        *cantPedidos = 0;
        arregloPedidos = (stPedido *)malloc(sizeof(stPedido));
    }

    return arregloPedidos;
}

int insertarPedido(char rutaArchivo[], stPedido pedido)
{
    FILE *archivoPedidos;
    int insercion = 0;

    /* Abre el archivo para agregar datos al final */
    archivoPedidos = fopen(rutaArchivo, MODO_ANADIR);  /* A�ade datos al final. Si el archivo no existe, es creado */

    if(archivoPedidos != NULL)
    {
        fwrite(&pedido, sizeof(pedido), 1, archivoPedidos);
        insercion = 1;
        fclose(archivoPedidos);
    }
    else
    {
        printfError("Ocurrio un error al querer abrir el archivo.");
    }

    return insercion;
}

/*  Se busca el registro que se quiere borrar. Cuando se encuentra, se sit�a en esa posici�n mediante la
    funci�n fseek y luego se modifica el campo clave de ese registro mediante alg�n valor de anulado, eso se logra
    con fwrite. Hasta all� se ha logrado una eliminaci�n L�GICA. Porque el registro sigue ocupando espacio en el archivo f�sico */
int anularPedido(char rutaArchivo[], int idPedido, int idCliente)
{
    stPedido pedidoAux;
    int elimina = 0;

    FILE *archivoPedidos;                             /* Abre el archivo para leer */
    archivoPedidos = fopen(rutaArchivo, MODO_LEC_ESCRIT);	/* Modo lectura/escritura. Si el archivo no existe, es creado */

    if(archivoPedidos != NULL)
    {
        fread(&pedidoAux, sizeof(pedidoAux), 1, archivoPedidos);
        while (!feof(archivoPedidos))
        {

            if (pedidoAux.idPedido == idPedido && pedidoAux.idCliente == idCliente)
            {
                fseek(archivoPedidos, ftell(archivoPedidos) - sizeof(pedidoAux), SEEK_SET); /* El puntero se encuentra al final del elemento entonces debemos hacer que retroceda*/

                pedidoAux.pedidoAnulado = PEDIDO_ANULADO;
                fwrite(&pedidoAux, sizeof(pedidoAux), 1, archivoPedidos);
                elimina = 1;

                break;
            }
            fread(&pedidoAux, sizeof(pedidoAux), 1, archivoPedidos);
        }

        /* Cierra el archivo */
        fclose(archivoPedidos);
    }
    else
    {
        printfError("Ocurrio un error al querer abrir el archivo.");
    }

    return elimina;
}

int modificarPedido(char rutaArchivo[], stPedido pedidoModificado)
{
    int modifica = 0;
    stPedido pedidoAux;

    FILE *archivoPedidos;
    archivoPedidos = fopen(rutaArchivo, MODO_LEC_ESCRIT); /* Abre el archivo para lectura/escritura */

    if(archivoPedidos != NULL)
    {
        fread(&pedidoAux, sizeof(pedidoAux), 1, archivoPedidos);
        while (!feof(archivoPedidos))
        {

            if (pedidoAux.idPedido == pedidoModificado.idPedido && pedidoAux.idCliente == pedidoModificado.idCliente)
            {

                fseek(archivoPedidos, ftell(archivoPedidos) - sizeof(pedidoModificado), SEEK_SET); /* El puntero se encuentra al final del elemento entonces debemos hacer que retroceda*/
                fwrite(&pedidoModificado, sizeof(pedidoModificado), 1, archivoPedidos);
                modifica = 1;
                break;
            }
            fread(&pedidoAux, sizeof(pedidoAux), 1, archivoPedidos);
        }

        fclose(archivoPedidos);
    }
    else
    {
        printfError("Ocurrio un error al querer abrir el archivo.");
    }

    return modifica;
}
