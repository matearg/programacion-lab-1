#include <stdio.h>

#include "mensajes.h"

void printfError(char mensaje[])
{
    printf("\nERROR: %s\n\n", mensaje);
}

void printfWarning(char mensaje[])
{
    printf("\nWARN: %s\n\n", mensaje);
}

void printfSucces(char mensaje[])
{
    printf("\nSUCC: %s\n\n", mensaje);
}

void barraTitulos()
{
    puts("\n ==========================================================================================");
}

void tituloPrincipal()
{
	barraTitulos();
	printf("\t\t\t     HaC Pedidos\n");
	printf("\t   Creacion, reportes, eliminacion, busqueda y actualizacion\n");
	printf("\t\t    Copyright 2022 | Laboratorio I\n");
	barraTitulos();
}

void tituloSecciones(char * titulo)
{
    barraTitulos();
    printf(" \t\t\t    ==> %s <==", titulo);
    barraTitulos();
}
