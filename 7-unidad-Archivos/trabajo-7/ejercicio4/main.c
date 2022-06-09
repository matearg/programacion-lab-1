#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio; //año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

void menu();
void cargarAlumnos(char archivo[]);
void mostrarAlumnos(char archivo[]);

int main()
{
    menu();

    return 0;
}

void menu()
{
    int opcion;
    do
    {
        system("cls");

        printf(
            "[1]Cargar alumnos\n"
            "[2]Ver alumnos\n"
            "[3]Salir\n"
            "\nIngrese una opcion: "
        );
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarAlumnos("alumnos.dat");
            break;
        case 2:
            mostrarAlumnos("alumnos.dat");
            break;
        }
    }
    while(opcion != 3);
}

void cargarAlumnos(char archivo[])
{
    stAlumno a;
    FILE *alumnos;
    char condicion;

    alumnos = fopen(archivo, "ab");

    if(alumnos != NULL)
    {
        do
        {
            system("cls");

            printf("Ingrese el legajo: ");
            fflush(stdin);
            scanf("%d", &a.legajo);

            printf("\nIngrese nombre y apellido: ");
            fflush(stdin);
            scanf("%s", a.nombreYapellido);

            printf("\nIngrese edad: ");
            fflush(stdin);
            scanf("%d", &a.edad);

            printf("\nIngrese anio: ");
            fflush(stdin);
            scanf("%d", &a.anio);

            fwrite(&a, sizeof(stAlumno), 1, alumnos);

            printf("Desea agregar otro alumno? s/n: ");
            fflush(stdin);
            scanf("%c", &condicion);
        }
        while(condicion == 's');
        fclose(alumnos);
    }
    else
    {
        printf("\nEl archivo no se abrio correctamente.");
    }
}

void mostrarAlumnos(char archivo[])
{
    FILE *alumnos;
    stAlumno a;
    int i = 0;

    alumnos = fopen(archivo, "rb");

    system("cls");

    if(alumnos != NULL)
    {
        while(fread(&a, sizeof(stAlumno), 1, alumnos) > 0)
        {
            printf("\nRegistro numero %d:\n", i++);
            printf("%d %s %d %d\n", a.legajo, a.nombreYapellido, a.edad, a.anio);
        }
        system("pause");
        fclose(alumnos);
    }
    else
    {
        printf("El archivo no se abrio correctamente.");
    }
}
