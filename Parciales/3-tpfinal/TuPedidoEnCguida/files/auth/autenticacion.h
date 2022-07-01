#ifndef AUTENTICACION_H_INCLUDED
#define AUTENTICACION_H_INCLUDED

#include "../clientes/cliente.h"
#include "../common/commonClientes.h"
#include "../common/mensajes.h"
#include "../common/leerTeclado.h"

/* Login del usuario */
int login(arrClientes *arregloClientes, char archivoClientes[]);

#endif // AUTENTICACION_H_INCLUDED
