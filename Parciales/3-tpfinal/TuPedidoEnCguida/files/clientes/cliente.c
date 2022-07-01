#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../common/mensajes.h"
#include "../common/commonClientes.h"
#include "../common/leerTeclado.h"

#include "cliente.h"
#include "archivosClientes.h"

void altaCliente(arrClientes *arregloClientes)
{
    int cant = arregloClientes->numClientes;
    stCliente aux;

    if (cant == 0)
    {
        arregloClientes->numClientes = 0;
        arregloClientes->clientes = (stCliente*)malloc(sizeof(stCliente));
    }
    else
    {
        arregloClientes->clientes = (stCliente*)realloc(arregloClientes->clientes, sizeof(stCliente) * (cant + 1));
    }

    system("cls");

    tituloSecciones("AGREGAR UN NUEVO CLIENTE");

    strcpy(aux.mail, leerEmail(arregloClientes));

    strcpy(aux.userName, leerString("\nIngrese el username del cliente: ", 20));

    strcpy(aux.password, leerString("\nIngrese el password del cliente: ", 20));

    strcpy(aux.nombre, leerString("\nIngrese el nombre del cliente: ", 30));

    strcpy(aux.apellido, leerString("\nIngrese el apellido del cliente: ", 30));

    aux.genero = leerGenero();
    aux.rol = leerRol();

    aux.idCliente = cant;

    aux.activo = 0;
    int insertado = insertarCliente(ARCHIVO_CLIENTES, aux);

    if(insertado == 1)
    {
        arregloClientes->clientes[cant] = aux;
        arregloClientes->numClientes++;
    }
    else
    {
        printfError("Ocurrio un error al insertar el nuevo cliente");
    }
}

void bajaCliente(arrClientes *arregloClientes, int idClienteLogeado)
{
    int idCliente, opcion = 0;

    if(arregloClientes->clientes[idClienteLogeado].rol == CLIENTE_ADMIN)
    {
        system("cls");
        listadoClientes(arregloClientes, "ANULACION DE CLIENTES");

        printf("\nSeleccione por id al cliente que desea anular: ");
        scanf("%d", &idCliente);

        int desactivar = desactivarCliente(ARCHIVO_CLIENTES, idCliente);

        if(desactivar == 1)
        {
            arregloClientes->clientes[idCliente].activo = 1;
            puts("\n\n ! Archivo modificado con exito. !");
        }
        else
        {
            printfError("Ha ocurrido un error al intentar desactivar el cliente");
        }
    }
    else
    {
        system("cls");
        tituloSecciones("BAJA DEL CLIENTE");
        printf("\n¿Esta seguro que desea desactivar el usuario? (0- No/ 1- Si)\n");
        scanf("%d", &opcion);

        if(opcion == 1)
        {
            arregloClientes->clientes[idClienteLogeado] = leerCamposAEditar(arregloClientes->clientes[idClienteLogeado]);
        }
    }
}

void modificacionCliente(arrClientes *arregloClientes, int idClienteLogeado)
{
    int pos = 0;

    if(arregloClientes->clientes[idClienteLogeado].rol == CLIENTE_ADMIN)
    {
        pos = pedirCliente(arregloClientes, "\nSeleccione por id de cliente a buscar: ");
        arregloClientes->clientes[pos] = leerCamposAEditar(arregloClientes->clientes[pos]);
    }
    else
    {
        arregloClientes->clientes[idClienteLogeado] = leerCamposAEditar(arregloClientes->clientes[idClienteLogeado]);
        pos = idClienteLogeado;
    }

    int modificado = modificarCliente(ARCHIVO_CLIENTES, arregloClientes->clientes[pos]);

    if(modificado == 1)
    {
        puts("\n\n ! Archivo modificado con exito. !");
    }
    else
    {
        printfError("Ha ocurrido un error al intentar modificar el cliente");
    }

    printf("\n");
    system("pause");
}

void listadoClientes(arrClientes *arregloClientes, char *tituloListado)
{
    int i = 0, clientesAnulados = 0;

    system("cls");

    tituloSecciones(tituloListado);
    printf("%8s\t%8s%15s%20s%20s", "IDCLIENTE", "NOMBRE", "APELLIDO", "USERNAME", "MAIL");
    barraTitulos();

    for(i = 0; i < arregloClientes->numClientes; i++)
    {
        if(arregloClientes->clientes[i].activo != 1)
        {
            printf("\n%8d\t%8s\t%8s\t%-18.18s\t  %-20.20s", arregloClientes->clientes[i].idCliente, arregloClientes->clientes[i].nombre,
                   arregloClientes->clientes[i].apellido,
                   arregloClientes->clientes[i].userName,
                   arregloClientes->clientes[i].mail
                  );
        }
        else
        {
            clientesAnulados++;
        }
    }
    puts("\n");
    barraTitulos();
    if(clientesAnulados == 0)
    {
        printf("\t\t\tNo hay clientes anulados");
    }
    else
    {
        printf("\t\t\tClientes anulados: %d", clientesAnulados);
    }
    barraTitulos();

    puts("\n");
    system("pause");
}

stCliente leerCamposAEditar(stCliente cliente)
{
    int opcion = 0;
    do
    {
        system("cls");
        opcion = listarCamposEditables(cliente);

        system("cls");
        switch(opcion)
        {
        case 1:
            strcpy(cliente.nombre, leerStringCampoEditable(2, "Nombre", cliente.nombre));
            break;
        case 2:
            strcpy(cliente.apellido, leerStringCampoEditable(2, "Apellido", cliente.apellido));
            break;
        case 3:
            strcpy(cliente.mail, leerStringCampoEditable(2, "Mail", cliente.mail));
            break;
        case 4:
            barraTitulos();
            printf("\n\n 1-   Genero: %c", cliente.genero);
            cliente.genero = leerGenero();
            barraTitulos();
            break;
        case 5:
            barraTitulos();
            printf("\n\n 1-   Rol: %d", cliente.rol);
            cliente.rol = leerRol();
            barraTitulos();
            break;
        default:
            break;
        }
    }
    while(opcion != 0);

    return cliente;
}

int buscarPosicionCliente(arrClientes arregloClientes, int idCliente)
{
    int encontrado = 0, pos = 0;
    while(pos<=arregloClientes.numClientes && encontrado == 0)
    {
        if(arregloClientes.clientes[pos].activo != 1 && arregloClientes.clientes[pos].idCliente == idCliente)
        {
            encontrado = 1;
        }
        else
        {
            pos++;
        }
    }

    if(encontrado == 0)
    {
        pos = -1;
    }
    return pos;
}

int buscarClientePorUsuario(arrClientes arregloClientes, char *userName, char *password)
{
    int encontrado = 0, pos = 0;

    while(pos<=arregloClientes.numClientes && encontrado == 0 && encontrado != -1)
    {
        if(strcmp(arregloClientes.clientes[pos].userName, userName) == 0 &&
           strcmp(arregloClientes.clientes[pos].password, password) == 0)
        {
            if(arregloClientes.clientes[pos].activo == 0)
            {
                encontrado = -1;
            }
            else
            {
                encontrado = 1;
            }
        }
        else
        {
            pos++;
        }
    }

    if(encontrado == 0)
    {
        pos = -1;
    }
    return pos;
}

int listarCamposEditables(stCliente cliente)
{
    int opcion = 0;

    tituloSecciones("    MODIFICACION DE USUARIO    ");

    printf("\n 1-   Nombre: %s", cliente.nombre);
    printf("\n 2- Apellido: %s", cliente.apellido);
    printf("\n 3-     Mail: %s", cliente.mail);
    if(cliente.genero == 'M')
    {
        printf("\n 4-   Genero: Masculino");
    }
    else
    {
        printf("\n 4-   Genero: Femenino");
    }
    if(cliente.rol == 0)
    {
        printf("\n 5-      Rol: Usuario");
    }
    else
    {
        printf("\n 5-      Rol: Admin");
    }
    printf("\n\n 0-    Salir");

    puts("\n\n - ¿Que campo desea modificar?: ");
    scanf("%d", &opcion);

    return opcion;
}

int pedirCliente(arrClientes *arregloClientes, char *textoPedir)
{
    int pos = 0, idCliente;

    do
    {
        listadoClientes(arregloClientes, "LISTADO DE CLIENTES");

        if(arregloClientes->numClientes > 0)
        {
            printf(textoPedir);
            scanf("%d", &idCliente);

            pos = buscarPosicionCliente(*arregloClientes, idCliente);

            if(pos == -1)
            {
                printfWarning("El id ingresado no es correcto. Por favor intente de nuevo.");
                system("pause");
            }
        }
    }while(pos == -1);

    return pos;
}

void mostrarCliente(arrClientes *arregloClientes, int idCliente)
{
    stCliente cliente;

    if(arregloClientes->clientes[idCliente].rol == CLIENTE_ADMIN)
    {
        idCliente = pedirCliente(arregloClientes, "\nSeleccione por id de cliente a buscar: ");
    }
    cliente = arregloClientes->clientes[idCliente];

    system("cls");
    tituloSecciones("    DATOS DEL CLIENTE    ");

    printf("\n   Nombre: %s", cliente.nombre);
    printf("\n Apellido: %s", cliente.apellido);
    printf("\n     Mail: %s", cliente.mail);
    if(cliente.genero == 'M')
    {
        printf("\n   Genero: Masculino");
    }
    else
    {
        printf("\n   Genero: Femenino");
    }
    if(cliente.rol == 0)
    {
        printf("\n      Rol: Usuario");
    }
    else
    {
        printf("\n      Rol: Admin");
    }
    puts("\n");
    system("pause");
}
