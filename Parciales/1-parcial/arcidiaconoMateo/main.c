// Librerias incluidas en el proyecto
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "pila.h"

// Prototipado de las funciones
void placaVideoUsr(int mSeguro, int cantReps, Pila * p); // 1
void placaVideoRandom(int mSeguro, int cantReps, Pila * p); // 1
int ordenarValoresCoins(Pila origen, int a[], Pila * destino); // 2a y 2b
void mostrarArreglo(int a[], int validos); // 2b
int buscarMaximoArreglo(int a[], int validos); // 3a
int buscarMenorPila(Pila p); // 3b
int gananciaTotal(Pila p); // 3c
void maxMinTotal(int a[], Pila p, int validos, Pila original); // 3d
float promCoinsArreglo(int a[], int validos); // 4a
float porcNegPila(Pila p); // 4b
void promArregloPorcPila(int a[], int validos, Pila p); // 4c

// Funcion llamadora
int main() // 5
{
    int cantRepeticiones, modoSeguro, usrOrRandom;
    int validos = 0;
    int arregloB[100];
    Pila coinsPorDia, pilaA;
    inicpila(&coinsPorDia);
    inicpila(&pilaA);

    system("cls");

    printf("Cuantas veces desea minar ");
    scanf("%d", &cantRepeticiones);

    printf("\nDesea ingresar los valores por consola (0) o generarlos de manera aleatoria (1) ");
    scanf("%d", &usrOrRandom);

    printf("\nDesea utilizar el modo seguro 1 = on / 0 = off ");
    scanf("%d", &modoSeguro);

    system("cls");

    if(usrOrRandom == 0)
    {
        placaVideoUsr(modoSeguro, cantRepeticiones, &coinsPorDia);
    }
    else
    {
        placaVideoRandom(modoSeguro, cantRepeticiones, &coinsPorDia);
    }

    printf("Coins generadas por ciclo en un dia");
    mostrar(&coinsPorDia);

    validos = ordenarValoresCoins(coinsPorDia, arregloB, &pilaA);

    maxMinTotal(arregloB, pilaA, validos, coinsPorDia);

    promArregloPorcPila(arregloB, validos, pilaA);

    system("PAUSE");
    system("cls");

    return 0;
}

// Permite al usuario agregar las coins y los carga a una pila
void placaVideoUsr(int mSeguro, int cantReps, Pila * p)
{
    int i = 0, valorCoin;
    int restantes = cantReps;

    for(i = 0; i<cantReps; i++)
    {
        if(mSeguro == 1)
        {
            printf("Ingrese el valor de sus coins (entre 10 y 40) ");
            printf("(Restantes %d) -> ", restantes);
            scanf("%d", &valorCoin);

            restantes = restantes - 1;

            apilar(p, valorCoin);
        }
        else
        {
            printf("Ingrese el valor de sus coins (entre -20 y 100) ");
            printf("(Restantes %d) -> ", restantes);
            scanf("%d", &valorCoin);

            restantes = restantes - 1;

            apilar(p, valorCoin);
        }
    }
}

// Crea los valores de las coins de forma aleatoria y los carga a una pila
void placaVideoRandom(int mSeguro, int cantReps, Pila * p)
{
    srand(time(NULL));

    int i = 0;

    for(i=0; i<cantReps; i++)
    {
        if(mSeguro == 1)
        {
            apilar(p, rand()%31 + 10);
        }
        else
        {
            apilar(p, rand()%121 - 20);
        }
    }
}

// Ordena la pila en la cual estan ubicados los coins de < a >
int ordenarValoresCoins(Pila origen, int a[], Pila * destino)
{
    int i = 0;

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&origen))
    {
        apilar(&aux, desapilar(&origen));

        if(tope(&aux) <= 100 && tope(&aux) > 40)
        {
            a[i] = tope(&aux);
            i++;
        }
        else
        {
            apilar(destino, desapilar(&aux));
        }
    }

    return i;
}

// Funcion que muestra los valores de un array separados por "|"
void mostrarArreglo(int a[], int validos)
{
    int i = 0;

    for(i=0; i<validos; i++)
    {
        printf("| %d ", a[i]);
    }
}

// Busca el maximo valor en un array y lo muestra por pantalla
int buscarMaximoArreglo(int a[], int validos)
{
    int i = 0, mayor = 0;

    mayor = a[i];

    for (i=1; i<validos; i++)
    {
        if(a[i]>mayor)
        {
            mayor = a[i];
        }
    }

    return mayor;
}

// Busca el menor valor en una pila y lo muestra por pantalla
int buscarMenorPila(Pila p)
{
    Pila aux, menor;
    inicpila(&aux);
    inicpila(&menor);

    if(!pilavacia(&p))
    {
        apilar(&menor, desapilar(&p));

        while(!pilavacia(&p))
        {
            if(tope(&p)<tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&p));
            }
            else
            {
                apilar(&aux, desapilar(&p));
            }
        }
        while(!pilavacia(&aux))
        {
            apilar(&p, desapilar(&aux));
        }
    }

    return tope(&menor);
}

// Muestra por pantalla una sumatoria de los valores de la pila
int gananciaTotal(Pila p)
{
    int suma = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        apilar(&aux, desapilar(&p));
        suma += tope(&aux);
    }

    return suma;
}

// Llama a las funciones "mayorArreglo()", "menorPila()" y "gananciaTotal()"
void maxMinTotal(int a[], Pila p, int validos, Pila original)
{
    int mayorArreglo = 0, menorPila = 0, total = 0;

    mayorArreglo = buscarMaximoArreglo(a, validos);

    if(mayorArreglo > 40)
    {
        printf("\n\nArreglo luego de ordenar\n\n");
        mostrarArreglo(a, validos);
        printf("\n\nEl valor maximo es %d", mayorArreglo);

        printf("\n\nPila luego de ordenar");
        mostrar(&p);
    }

    menorPila = buscarMenorPila(p);

    printf("El valor minimo es %d\n", menorPila);

    total = gananciaTotal(original);

    printf("\nLa ganancia total del dia es %d\n", total);
}

// Muestra en pantalla el promedio de coins de un arreglo
float promCoinsArreglo(int a[], int validos)
{
    int i = 0, suma = 0;
    float promedio = 0;

    for(i=0; i<validos; i++)
    {
        suma += a[i];
    }

    promedio = (float)suma / validos;

    return promedio;
}


// Muestra por pantalla el porcentaje de valores negativos de una pila
float porcNegPila(Pila p)
{
    int i = 0, j = 0;
    float porcentage = 0;

    Pila aux;
    inicpila(&aux);

    while (!pilavacia(&p))
    {
        apilar(&aux, desapilar(&p));
        j++;
    }

    while (!pilavacia(&aux))
    {
        apilar(&p, desapilar(&aux));

        if(tope(&p) < 0)
        {
            i = i + 1;
        }
    }

    porcentage = (float)i / j * 100;

    return porcentage;
}

// Llama a las funciones "promCoinsArreglo()" y "porcNegPila()"
void promArregloPorcPila(int a[], int validos, Pila p)
{
    float promedioCoins = 0, porcNegativos = 0;

    promedioCoins = promCoinsArreglo(a, validos);

    if (promedioCoins > 0)
    {
        printf("\nEl promedio de coins almacenadas en el arreglo es %.2f\n", promedioCoins);
    }

    porcNegativos = porcNegPila(p);

    printf("\nEl porcentaje de numeros negativos de la pila es %.2f\n\n", porcNegativos);
}
