#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdio.h>
#include <time.h>

#define DIM_FECHA 18

/* Carga un string con la fecha y la hora de ejecucion y lo retorna */
char * fechaYHora(char fechaHora[DIM_FECHA]);

/* Muestra la fecha y hora actuales */
void mostrarFecha();

#endif // FECHA_H_INCLUDED
