#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumnos;

int cargaManual(stAlumnos arreglo[], int dim);
void mostarAlumno(stAlumnos arreglo[], int validos);
void mostarAlumnos(stAlumnos arreglo[], int validos);

int main()
{
    stAlumnos listaAlumnos[100];
    int validos = 0;

    validos = cargaManual(listaAlumnos, 100);

    mostarAlumnos(listaAlumnos, validos);

    return 0;
}

int cargaManual(stAlumnos arreglo[], int dim)
{
    int i = 0;
    char condicion;

    do
    {
        system("cls");
        printf("Ingrese el nombre del alumno: ");
        fflush(stdin);
        gets(arreglo[i].nombre);

        printf("Ingrese el genero del alumno m/f/o: ");
        fflush(stdin);
        scanf("%c", &arreglo[i].genero);

        arreglo[i].matricula = i + 1;
        i++;

        printf("Desea agregar otro alumno? s/n ");
        fflush(stdin);
        condicion = getchar();
    }
    while (condicion != 'n' && i < dim);

    return i;
}

void mostarAlumnos(stAlumnos arreglo[], int validos)
{
    int i = 0;

    system("cls");

    for(i = 0; i < validos; i++)
    {
        printf("%d %s %c\n", arreglo[i].matricula, arreglo[i].nombre, arreglo[i].genero);
    }
}
