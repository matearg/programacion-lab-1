#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/fecha.h"

typedef struct
{
    int idPedido;      // auto incremental
    int idCliente;     // este valor corresponde al id del cliente que realizó el pedido
    char fecha[DIM_FECHA];    // dd/MM/aaaa
    float costoTotal;  // sumatoria de precio por unidad
    int pedidoAnulado; // indica 1 o 0 si el pedido fue anulado o no
} stPedido;

typedef struct
{
    stPedido * pedidos;
    int numPedidos;
} arrPedidos;

/* Permite cargar un pedido (alta) */
void altaPedido(arrPedidos *arregloPedidos, int idCliente);

/* Permite anular un pedido (baja logica) */
void bajaPedido(arrPedidos *arregloPedidos, int idCliente);

/* Permite modificar un pedido ya cargado */
void modificacionPedido(arrPedidos *arregloPedidos, int idCliente);

/* Lista los pedidos cargados */
void listadoPedido(arrPedidos *arregloPedidos, int idCliente);

/* Lista los pedidos y le pide al usuario que elija uno, retorna el id del pedido elegido */
int elegirPedido(arrPedidos *arregloPedidos, int idCliente);

#endif // PEDIDOS_H_INCLUDED
