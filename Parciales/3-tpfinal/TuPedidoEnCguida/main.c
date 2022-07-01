#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "files/auth/autenticacion.h"

#include "files/menu/menu.h"

int main()
{
    setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */

    int idClienteLogeado = 0;

    arrPedidos arregloPedidos;
    arrClientes arregloClientes;

    arregloPedidos.pedidos = obtenerPedidos(ARCHIVO_PEDIDO, &arregloPedidos.numPedidos);
    arregloClientes.clientes = obtenerClientes(ARCHIVO_CLIENTES, &arregloClientes.numClientes);

    idClienteLogeado = login(&arregloClientes, ARCHIVO_CLIENTES);

    menuPrincipal(&arregloPedidos, &arregloClientes, ARCHIVO_PEDIDO, ARCHIVO_CLIENTES, idClienteLogeado);

    return 0;
}

