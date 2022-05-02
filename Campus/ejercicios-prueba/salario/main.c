#include <stdio.h>

int main()
{
    int salarioPorDia, dias, salario = 0;

    printf("Cuantos dias vas a trabajar: ");
    scanf("%d", &dias);

    printf("Cuanto te van a pagar por dia: $");
    scanf("%d", &salarioPorDia);

    salario = salarioPorDia * dias;

    printf("Te van a pagar al completarse la semana $%d", salario);

    return 0;
}
