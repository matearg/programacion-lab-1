#ifndef ARCHIVOSCLIENTES_H_INCLUDED
#define ARCHIVOSCLIENTES_H_INCLUDED

#include "cliente.h"

#define CLIENTE_ACTIVO 0
#define CLIENTE_DESACTIVADO 1

#define ARCHIVO_CLIENTES "clientes.dat"

void cargarClientesArchivo(char rutaArchivo[], stCliente arregloClientes[], int dim);
stCliente * obtenerClientes(char rutaArchivo[], int * cantClientes);
int insertarCliente(char rutaArchivo[], stCliente cliente);
int desactivarCliente(char rutaArchivo[], int idCliente);
int modificarCliente(char rutaArchivo[], stCliente clienteModificado);


#endif // ARCHIVOSCLIENTES_H_INCLUDED
