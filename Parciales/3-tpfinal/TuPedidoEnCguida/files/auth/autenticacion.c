#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "autenticacion.h"

int login(arrClientes *arregloClientes, char archivoClientes[])
{
    int encontrado = 0;
    char userName[20], password[20];

    system("cls");
    tituloPrincipal();

    if(arregloClientes->numClientes > 0)
    {
        do
        {
            strcpy(userName, leerString("\nIngrese el username del cliente: ", 20));

            strcpy(password, leerPassword());

            encontrado = buscarClientePorUsuario(*arregloClientes, userName, password);

            if(encontrado == -1)
            {
                system("cls");
                tituloPrincipal();
                printfError("El usuario ingresado no es valido, por favor ingrese correctamente los datos.\n\n");
                system("pause");
                system("cls");
                tituloPrincipal();
            }

        }while(encontrado == -1);
    }
    else
    {
        printf("\nMuchas gracias por confiar en nosotros y comprar nuestro sistema. \nPor favor ingrese los datos del primer usuario.\n");
        barraTitulos();
        system("pause");

        altaCliente(arregloClientes);
        encontrado = arregloClientes->clientes[0].idCliente;
    }

    return encontrado;
}
