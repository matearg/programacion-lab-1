// Librerias incluidas en el proyecto
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

// Prototipado de las funciones
void placaVideoRandom(); // 1
int ordenarValoresCoins(); // 2a y 2b
void mostrarArreglo(int a[], int validos); // 2b
int buscarMaximoArreglo(); // 3a
int buscarMenorPila(); // 3b
int gananciaTotal(); // 3c
void maxMinTotal(); // 3d
float promCoinsArreglo(); // 4a
int porcNegPila(); // 4b
void promArregloPorcPila(); // 4c

// Funcion principal
int main() // 5
{
    return 0;
}

// Crea los valores de las coins de forma aleatoria y los carga a una pila
void placaVideoRandom()
{
}

// Ordena la pila en la cual estan ubicados los coins de < a >
int ordenarValoresCoins()
{
}

// Funcion que muestra los valores de un array separados por "|"
void mostrarArreglo(int a[], int validos)
{
    int i = 0;

    for(i=0; i<validos; i++)
    {
        printf("| %d ", a[i]);
    }
    printf("|");
}

// Busca el maximo valor en un array y lo muestra por pantalla
int buscarMaximoArreglo()
{
}

// Busca el menor valor en una pila y lo muestra por pantalla
int buscarMenorPila()
{
}

// Muestra por pantalla una sumatoria de los valores de la pila
int gananciaTotal()
{
}

// Llama a las funciones "mayorArreglo()", "menorPila()" y "gananciaTotal()"
void maxMinTotal()
{
}

// Muestra en pantalla el promedio de coins de un arreglo
float promCoinsArreglo()
{
}


// Muestra por pantalla el porcentaje de valores negativos de una pila
int porcNegPila()
{
}

// Llama a las funciones "promCoinsArreglo()" y "porcNegPila()"
void promArregloPorcPila()
{
}
