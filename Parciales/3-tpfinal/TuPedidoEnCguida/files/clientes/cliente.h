#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define CAMPOS_EDITABLES 7

#define CLIENTE_ADMIN 1
#define CLIENTE_USUARIO 0

typedef struct
{
    int idCliente; // auto incremental
    char nombre[30];
    char apellido[30];
    char userName[20];
    char password[20];
    char mail[30];
    char genero;
    int rol;     // 1: es admin - 0: es común
    int activo; // indica 1 o 0 si el cliente está activo
} stCliente;

typedef struct
{
    stCliente * clientes;
    int numClientes;
} arrClientes;

void altaCliente(arrClientes *arreglo);
void bajaCliente(arrClientes *arreglo, int idClienteLogeado);
void modificacionCliente(arrClientes *arreglo, int idClienteLogeado);
void listadoClientes(arrClientes *arregloClientes, char *tituloListado);

int buscarPosicionCliente(arrClientes arregloClientes, int idCliente);
int buscarClientePorUsuario(arrClientes arregloClientes, char *userName, char *password);

stCliente leerCamposAEditar(stCliente cliente);
int listarCamposEditables(stCliente cliente);

int pedirCliente(arrClientes *arregloClientes, char *textoPedir);
void mostrarCliente(arrClientes *arregloClientes, int idCliente);

#endif // CLIENTE_H_INCLUDED
