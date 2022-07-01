#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

void menuPrincipal(arrPedidos *arregloPedidos, arrClientes *arregloClientes, char archivoPedidos[], char archivoClientes[], int idClienteLogeado)
{
    int opcion = 0;

    do
    {
        system("cls");
        tituloPrincipal();
        printf
        (
            "\n\n[1] Pedidos\n"
            "[2] Clientes\n\n"
            "[0] Salir\n\n"
        );
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            menuPedidos(arregloPedidos, arregloClientes, archivoPedidos, idClienteLogeado);
            break;
        case 2:
            menuClientes(arregloClientes, archivoClientes, idClienteLogeado);
            break;
        case 0:
            printf("\nAdios!\n");
            exit(0);
            break;
        default:
            printfError("Opcion invalida...");
            break;
        }
    }
    while (opcion != 0);
}

void menuPedidos(arrPedidos *arregloPedidos, arrClientes *arregloClientes, char nombreArchivo[], int idClienteLogeado)
{
    int opcion = 0, idClienteAltaPedido;

    do
    {
        system("cls");

        tituloSecciones("PEDIDOS");

        printf
        (
            "\n[1] Alta\n"
            "[2] Baja\n"
            "[3] Modificacion\n"
            "[4] Listado\n\n"
            "[0] Salir\n\n"
        );

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            idClienteAltaPedido = pedirCliente(arregloClientes, "\nSeleccione por id de cliente al cual desea agregar el pedido: ");
            altaPedido(arregloPedidos, idClienteAltaPedido);
            break;
        case 2:
            bajaPedido(arregloPedidos, idClienteLogeado);
            break;
        case 3:
            modificacionPedido(arregloPedidos, idClienteLogeado);
            break;
        case 4:
            idClienteAltaPedido = pedirCliente(arregloClientes, "\nSeleccione por id del cliente del cual desea listar los pedidos: ");
            listadoPedido(arregloPedidos, idClienteAltaPedido);
            break;
        case 0:
            break;
        default:
            printfError("Opcion invalida...");
            break;
        }

    }
    while (opcion != 0);
}

void menuClientes(arrClientes *arregloClientes, char nombreArchivo[], int idClienteLogeado)
{
    if(arregloClientes->clientes[idClienteLogeado].rol == 1)
    {
        menuClientesAdm(arregloClientes, nombreArchivo, idClienteLogeado);
    }
    else
    {
        menuClientesUsuario(arregloClientes, nombreArchivo, idClienteLogeado);
    }
}

void menuClientesAdm(arrClientes *arregloClientes, char nombreArchivo[], int idCliente)
{
    int opcion = 0;

    do
    {
        system("cls");

        tituloSecciones("MANEJO CLIENTES ADMIN");

        printf
        (
            "\n[1] Alta\n"
            "[2] Baja\n"
            "[3] Modificacion\n"
            "[4] Listado\n"
            "[5] Buscar cliente\n\n"
            "[0] Salir\n\n"
        );

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            altaCliente(arregloClientes);
            break;
        case 2:
            bajaCliente(arregloClientes, idCliente);
            break;
        case 3:
            modificacionCliente(arregloClientes, idCliente);
            break;
        case 4:
            listadoClientes(arregloClientes, "LISTADO");
            break;
        case 5:
            mostrarCliente(arregloClientes, idCliente);
        case 0:
            break;
        default:
            printfError("Opcion invalida...");
            break;
        }

    }
    while (opcion != 0);
}

void menuClientesUsuario(arrClientes *arregloClientes, char nombreArchivo[], int idCliente)
{
    int opcion = 0;

    do
    {
        system("cls");

        tituloSecciones("MANEJO CLIENTES USUARIO");

        printf
        (
            "\n[1] Modificacion\n"
            "[2] Baja\n"
            "[3] Listado\n"
            "[4] Mostrar datos de usuario\n\n"
            "[0] Salir\n\n"
        );

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            modificacionCliente(arregloClientes, idCliente);
            break;
        case 2:
            bajaCliente(arregloClientes, idCliente);
            break;
        case 3:
            listadoClientes(arregloClientes, "LISTADO");
            break;
        case 4:
            mostrarCliente(arregloClientes, idCliente);
        case 0:
            break;
        default:
            printfError("Opcion invalida...");
            break;
        }

    }
    while (opcion != 0);
}
