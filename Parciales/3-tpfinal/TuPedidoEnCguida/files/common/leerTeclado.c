#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leerTeclado.h"

char leerCaracter(char textoIngresar[TEXTO_MAX])
{
    char caracter;

    puts(textoIngresar);
    fflush(stdin);
    scanf("%c", &caracter);

    return caracter;
}

char * leerString(char textoIngresar[TEXTO_MAX], int tamanio)
{
    static char caracteres[30];

    puts(textoIngresar);
    fflush(stdin);
    gets(caracteres);

    return caracteres;
}
