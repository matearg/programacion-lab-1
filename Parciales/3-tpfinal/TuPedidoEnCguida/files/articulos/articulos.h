#ifndef ARTICULOS_H_INCLUDED
#define ARTICULOS_H_INCLUDED

#include <stdio.h>
#include <string.h>

/* Lista los articulos cargados en un arreglo */
void listadoArticulos();

/* Muestra por pantalla un articulo segun su id */
void mostrarArticuloPorId(int idArticulo);

/* Calcula el precio de un articulo en la cantidad deseada segun su id */
int precioPorId(int idArticulo);

/* Consulta al ususario la cantidad de unidades que quiere de un articulo y lo retorna */
int cantArticulos(int idArticulo);

/* Permite al usuario elejir los articulos retorna una sumatoria de sus costos */
float altaArticulos();


#endif // ARTICULOS_H_INCLUDED
