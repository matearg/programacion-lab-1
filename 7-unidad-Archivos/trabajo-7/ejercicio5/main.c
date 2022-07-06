#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int legajo;
  char nombre[30];
  char apellido[30];
  int edad;
  int anio;
} stAlumno;

typedef struct {
  stAlumno *alumno;
  int cantAlumnos;
} arrAlumnos;

const char *LECTURA_ESCRITURA = "r+b";
const char *LECTURA = "rb";
const char *ANADIR = "ab";

stAlumno *obtenerAlumnos(char nombreArchivo[], int *cantAlumnos);
void altaAlumno(arrAlumnos *arregloAlumnos, char nombreArchivo[]);
int insertarAlumno(char nombreArchivo[], stAlumno alumno);
int getAnio(int edadAlumno);
void mostrarAlumnos(arrAlumnos arregloAlumnos[]);
void menu(arrAlumnos *arregloAlumnos, char nombreArchivo[]);
int cantidadRegistros(char nombreArchivo[]);

int main() {
  arrAlumnos arregloAlumnos;

  arregloAlumnos.alumno =
      obtenerAlumnos("alumnos.dat", &arregloAlumnos.cantAlumnos);

  menu(&arregloAlumnos, "alumnos.dat");

  return 0;
}

stAlumno *obtenerAlumnos(char nombreArchivo[], int *cantAlumnos) {
  int i;
  stAlumno alumnoAux;
  stAlumno *arregloAlumnos;

  FILE *archivoAlumnos = NULL;
  archivoAlumnos = fopen(nombreArchivo, LECTURA);

  if (archivoAlumnos != NULL) {
    fseek(archivoAlumnos, 0, SEEK_END);
    *cantAlumnos = ftell(archivoAlumnos) / sizeof(stAlumno);
    arregloAlumnos = (stAlumno *)malloc((*cantAlumnos) * sizeof(stAlumno));

    fseek(archivoAlumnos, 0, SEEK_SET);
    fread(&alumnoAux, sizeof(alumnoAux), 1, archivoAlumnos);
    i = 0;

    while (!feof(archivoAlumnos)) {
      arregloAlumnos[i++] = alumnoAux;
      fread(&alumnoAux, sizeof(alumnoAux), 1, archivoAlumnos);
    }

    fclose(archivoAlumnos);
  } else {
    printf("\nNo se pudo abrir el archivo\n");

    *cantAlumnos = 0;
    arregloAlumnos = (stAlumno *)malloc(sizeof(stAlumno));
  }

  return arregloAlumnos;
}

void altaAlumno(arrAlumnos *arregloAlumnos, char nombreArchivo[]) {
  int cant = arregloAlumnos->cantAlumnos;
  int insertado = 0;
  stAlumno aux;

  if (cant == 0) {
    arregloAlumnos->cantAlumnos = 0;
    arregloAlumnos->alumno = (stAlumno *)malloc(sizeof(stAlumno));
  } else {
    arregloAlumnos->alumno = (stAlumno *)realloc(arregloAlumnos->alumno,
                                                 sizeof(stAlumno) * cant + 1);
  }

  system("cls");
  printf("Hello, Archivos\n");

  aux.legajo = cant;

  printf("\nIngrese la edad del alumno: ");
  scanf("%d", &aux.edad);

  printf("\nIngrese el nombre del alumno: ");
  fflush(stdin);
  gets(aux.nombre);

  printf("\nIngrese el apellido del alumno: ");
  fflush(stdin);
  gets(aux.apellido);

  aux.anio = getAnio(aux.edad);

  insertado = insertarAlumno(nombreArchivo, aux);

  if (insertado == 1) {
    arregloAlumnos->alumno[cant] = aux;
    arregloAlumnos->cantAlumnos++;
  } else {
    printf("\nOcurrio un error al insertar el alumno\n\n");
  }

  puts("\n");
}

int insertarAlumno(char nombreArchivo[], stAlumno alumno) {
  FILE *archivoAlumnos;
  int insertado = 0;

  archivoAlumnos = fopen(nombreArchivo, ANADIR);

  if (archivoAlumnos != NULL) {
    fwrite(&alumno, sizeof(alumno), 1, archivoAlumnos);
    insertado = 1;
    fclose(archivoAlumnos);
  } else {
    printf("\nNo se pudo abrir el archivo\n");
  }

  return insertado;
}

void menu(arrAlumnos *arregloAlumnos, char nombreArchivo[]) {
  char opcion;

  do {
    system("cls");
    printf("MENU\n");
    printf("\n[C]argar Alumno"
           "\n[M]ostar Alumnos"
           "\n\n[S]alir\n");
    printf("\nElija una opcion -> ");
    fflush(stdin);
    opcion = getchar();

    switch (opcion) {
    case 'C':
      altaAlumno(arregloAlumnos, nombreArchivo);
      system("pause");
      break;

    case 'M':
      mostrarAlumnos(arregloAlumnos);
      system("pause");
      break;

    case 'S':
      system("cls");
      printf("Adios!");
      break;

    default:
      printf("\nOpcion incorrecta\n");
      system("pause");
      break;
    }
  } while (opcion != 'S');
}

void mostrarAlumnos(arrAlumnos *arregloAlumnos) {
  int i = 0;

  system("cls");
  printf("LISTADO\n\n");

  for (i = 0; i < arregloAlumnos->cantAlumnos; i++) {
    printf("%d ", arregloAlumnos->alumno[i].legajo);
    printf(" %s ", arregloAlumnos->alumno[i].nombre);
    printf("%s ", arregloAlumnos->alumno[i].apellido);
    printf(" %d ", arregloAlumnos->alumno[i].edad);
    printf(" %d", arregloAlumnos->alumno[i].anio);
    puts("\n");
  }
}

int getAnio(int edadAlumno) {
  int anio;

  if (edadAlumno == 13) {
    anio = 1;
  } else if (edadAlumno == 14) {
    anio = 2;
  } else if (edadAlumno == 15) {
    anio = 3;
  } else if (edadAlumno == 16) {
    anio = 4;
  } else if (edadAlumno == 17) {
    anio = 5;
  } else if (edadAlumno == 18) {
    anio = 6;
  } else {
    anio = 0;
  }

  return anio;
}

int cantidadRegistros(char nombreArchivo[]) {
  int i;

  FILE *archivo;
  archivo = fopen(nombreArchivo, LECTURA);

  if (archivo != NULL) {
  }

  return i;
}
