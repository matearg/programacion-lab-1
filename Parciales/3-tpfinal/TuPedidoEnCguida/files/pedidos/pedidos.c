#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "../common/mensajes.h"
#include "../common/leerTeclado.h"
#include "../articulos/articulos.h"
#include "../clientes/cliente.h"
#include "../common/fecha.h"

#include "pedidos.h"
#include "archivosPedidos.h"

void altaPedido(arrPedidos *arregloPedidos, int idCliente)
{
    int cant = arregloPedidos->numPedidos;
    float sumCosto = 0;
    int insertado = 0;
    stPedido aux;
    char control;
    char fecha[DIM_FECHA];

    if(cant == 0)
    {
        /* establece el numero de pedidos en 0 si no hay ninguno cargado */
        arregloPedidos->numPedidos = 0;
        arregloPedidos->pedidos = (stPedido*)malloc(sizeof(stPedido));
    }
    else
    {
        /* crea espacio para un pedidio nuevo */
        arregloPedidos->pedidos = (stPedido*)realloc(arregloPedidos->pedidos, sizeof(stPedido) * cant + 1);
    }

    system("cls");
    tituloSecciones("ALTA PEDIDO");

    sumCosto = altaArticulos();

    if (sumCosto != 0)
    {
        /* pasaje de variables al arreglo */
        aux.costoTotal = sumCosto;

        aux.idCliente = idCliente;

        aux.idPedido = cant;

        aux.pedidoAnulado = 0;

        strcpy(aux.fecha, fechaYHora(fecha));

        insertado = insertarPedido(ARCHIVO_PEDIDO, aux);

        if (insertado == 1)
        {
            arregloPedidos->pedidos[cant] = aux;
            arregloPedidos->numPedidos++;
            printfSucces("El pedido se cargo correctamente");
            system("pause");
        }
        else
        {
            printfWarning("El pedido no se cargo correctamente");
            system("pause");
            altaPedido(arregloPedidos, idCliente);
        }
    }
    else
    {
        printf("WARN: El pedido no se agrego correctamente, desea cargarlo nuevamente s/n: ");
        fflush(stdin);

        control = getche();

        switch (control)
        {
        case 's':
            altaPedido(arregloPedidos, idCliente);
            break;
        case 'n':
            puts("\n\n");
            system("pause");
            break;
        default:
            printfError("El caracter ingresado no es valido...");
            system("pause");
            break;
        }
    }
}

void bajaPedido(arrPedidos *arregloPedidos, int idCliente)
{
    int idPedido;
    int anulado = 0;

    system("cls");

    tituloSecciones("BAJA DE PEDIDO");

    idPedido = elegirPedido(arregloPedidos, idCliente);

    arregloPedidos->pedidos[idPedido].pedidoAnulado = 1;

    anulado = anularPedido(ARCHIVO_PEDIDO, idPedido, idCliente);

    if(anulado == 1)
    {
        printfSucces("El pedidos se anulo correctamente...");
    }
    else
    {
        printfError("El pedidos no se anulo correctamente...");
    }

    printf("\n");
    system("pause");
}

void modificacionPedido(arrPedidos *arregloPedidos, int idCliente)
{
    int modificado = 0, idPedido, sumCosto;
    char control;
    stPedido aux;

    system("cls");
    printf("MODIFICAR\n\n");

    idPedido = elegirPedido(arregloPedidos, idCliente);

    sumCosto = altaArticulos();

    if (sumCosto != 0)
    {
        /* pasaje de variables al arreglo */
        aux.costoTotal = sumCosto;

        arregloPedidos->pedidos[idPedido].costoTotal = aux.costoTotal;

        modificado = modificarPedido(ARCHIVO_PEDIDO, arregloPedidos->pedidos[idPedido]);

        if (modificado == 1)
        {
            printfSucces("El pedido se modifico correctamente");
            system("pause");
        }
        else
        {
            printfWarning("El pedido no se modifico correctamente");
            system("pause");
        }
    }
    else
    {
        printf("WARN: El nuevo costo del pedido es de $0 desea anularlo s/n: ");
        fflush(stdin);

        control = getche();

        switch (control)
        {
        case 's':
            bajaPedido(arregloPedidos, idCliente);
            break;
        case 'n':
            puts("\n\n");
            system("pause");
            break;
        default:
            printfError("El caracter ingresado no es valido...");
            system("pause");
            break;
        }
    }
}

void listadoPedido(arrPedidos *arregloPedidos, int idCliente)
{
    int i = 0, pedidosAnulados = 0;

    system("cls");
    tituloSecciones("LISTADO PEDIDOS");

    printf("%8s\t%8s\t%8s", "IDPEDIDO", "PRECIO", "FECHA");
    barraTitulos();

    for(i = 0; i < arregloPedidos->numPedidos; i++)
    {
        if(arregloPedidos->pedidos[i].pedidoAnulado != 1)
        {
            if(arregloPedidos->pedidos[i].idCliente == idCliente)
            {
                printf("\n%8d\t$%.2f         %s", arregloPedidos->pedidos[i].idPedido, arregloPedidos->pedidos[i].costoTotal, arregloPedidos->pedidos[i].fecha);
            }
        }
        else if(arregloPedidos->pedidos->idCliente == idCliente)
        {
            pedidosAnulados++;
        }
    }

    puts("\n");
    barraTitulos();

    if (pedidosAnulados == 0)
    {
        printf("\t\t\tNo hay pedidos anulados");
    }
    else
    {
        printf("\t\tPedidos anulados: %d", pedidosAnulados);
    }
    barraTitulos();

    system("pause");
}

int elegirPedido(arrPedidos *arregloPedidos, int idCliente)
{
    int pedidoElegido = 0;

    do
    {
        listadoPedido(arregloPedidos, idCliente);

        printf("Elija un pedido: ");
        scanf("%d", &pedidoElegido);

        if(idCliente != arregloPedidos->pedidos[pedidoElegido].idCliente)
        {
            printfWarning("El id de pedido no es valido...");
            system("pause");
        }
    } while (idCliente != arregloPedidos->pedidos[pedidoElegido].idCliente);

    return pedidoElegido;
}
