#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commonClientes.h"
#include "mensajes.h"
#include "leerTeclado.h"

char leerGenero()
{
    char genero;
    do
    {
        genero = leerCaracter("\nIngrese el genero del cliente(M/F): ");
    }
    while (genero != 'M' && genero != 'F');

    return genero;
}

int leerRol()
{
    int rol;

    fflush(stdin);
    do
    {
        puts("\nIngrese el rol del cliente(0- Usuario/1- Admin): ");
        scanf("%d", &rol);

        if(rol != 0 && rol != 1)
        {
            system("cls");
            printfError("Ingrese correctamente el numero del rol para el cliente.");
        }
    }
    while (rol != 0 && rol != 1);

    return rol;
}

char * leerEmail(arrClientes *arregloClientes)
{
    static char email[30];
    int valido = 0;

    do
    {
        system("cls");
        tituloSecciones("AGREGAR UN NUEVO CLIENTE");

        strcpy(email, leerString("\nIngrese el mail del cliente: ", 30));

        for(int i = 0; i<30; i++)
        {
            if(email[i] == '@')
            {
                valido = 1;
            }
        }

        if(valido == 0)
        {
            printfError("Por favor ingrese un correo electronico valido.");
            system("pause");
            system("cls");
        }
        else
        {
            valido = validarCorreo(arregloClientes, email);

            if(valido == 0)
            {
                printfError("El correo ingresado ya existe. Por favor ingrese un correo electronico valido.");
                system("pause");
                system("cls");
            }
        }
    }while(valido == 0);

    return email;
}

char * leerPassword()
{
    static char password[33];

    printf("\nIngrese el password del cliente: \n");
    int p=0;

    do{
        fflush(stdin);
        password[p]=getch();

        if(password[p]!='\r'){
            printf("*");
        }

        p++;

    }while(password[p-1]!='\r');

    password[p-1]='\0';
    return password;
}

char * leerStringCampoEditable(int numeroElegido, char *campo, char *campoValor)
{
    static char caracteres[30];
    printf(" ==============================================================================\n");
    printf("\t\t    ==> %d-   %s: %s <==\n", numeroElegido, campo, campoValor);
    printf(" ==============================================================================\n\n");
    puts("\n- Ingrese el nuevo valor: ");
    fflush(stdin);
    gets(caracteres);
    printf(" ==============================================================================\n");

    return caracteres;
}

int validarCorreo(arrClientes *arregloClientes, char * email)
{
    int i = 0, encontrado = 1;
    while(i < arregloClientes->numClientes && encontrado == 1)
    {
        if(strcmp(arregloClientes->clientes[i].mail, email) == 0)
        {
            encontrado = 0;
        }
        i++;
    }
    return encontrado;
}
