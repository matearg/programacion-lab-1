#include <stdio.h>
#include <stdlib.h>

// Realice una pequeña calculadora, utilizando funciones (una funcion de
// suma, una de multiplicacion, una de resta, una de division...)

void suma(float a, float b);
void resta(float a, float b);
void multiplicacion(float a, float b);
void division(float a, float b);
int menu();

int main(int argc, char *argv[])
{
    int selected, num1, num2;

    printf("Ingresa un numero ");
    scanf("%d", &num1);

    printf("Ingresa otro numero ");
    scanf("%d", &num2);

    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
            suma(num1, num2);
            break;
        case 2:
            resta(num1, num2);
            break;
        case 3:
            multiplicacion(num1, num2);
            break;
        case 4:
            division(num1, num2);
            break;
        case 0:
            printf("\nAdios\n");

            break;
        }

    }
    while(selected!=0);

    system("PAUSE");

    return 0;
}

int menu()
{
    int input;

    system("cls");

    printf("\nEjercicio 5: calculadora");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1-Sumar");
    printf("\n2-Restar");
    printf("\n3-Multiplica");
    printf("\n4-Dividir");
    printf("\n0-QUIT");

    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);

    return input;
}

void suma(float a, float b)
{
    float resultado = 0;

    resultado = a + b;

    printf("%f\n", resultado);

    system("PAUSE");
}

void resta(float a, float b)
{
    float resultado = 0;

    resultado = a - b;

    printf("%f\n", resultado);

    system("PAUSE");
}

void multiplicacion(float a, float b)
{
    float resultado = 0;

    resultado = a * b;

    printf("%f\n", resultado);

    system("PAUSE");
}

void division(float a, float b)
{
    float resultado = 0;

    resultado = a / b;

    printf("%f\n", resultado);

    system("PAUSE");
}
