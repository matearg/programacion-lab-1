#include <stdio.h>
#include <stdlib.h>

int main()
{
    char condicion;
    int cont = 0;

    do {
        cont++;
        printf("Hola, ");
        system("echo %username%");
        printf("\nQuiere que lo salude nuevamente s/n: ");
        fflush(stdin);
        scanf("%c", &condicion);
        system("cls");
    } while (condicion == 's');

    printf("Lo salude %d veces\n", cont);
    printf("Adios!\n");
    system("pause");

    return 0;
}
