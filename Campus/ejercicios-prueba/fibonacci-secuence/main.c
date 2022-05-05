#include <stdio.h>
#include <stdlib.h>

void fibonacci(int a, int b);

int main()
{
    int num1 = 0, num2 = 1;

    system("cls");

    fibonacci(num1, num2);

    printf("\n\n");

    system("PAUSE");
    system("cls");

    return 0;
}

void fibonacci(int a, int b)
{
    int numTerminos = 0, i = 0, sigTermino = 0;

    printf("Ingrese una cantidad de terminos ");
    scanf("%d", &numTerminos);

    printf("\nFibonacci secuence: %d %d ", a, b);

    for(i=2;i<numTerminos;i++)
    {
        sigTermino = a + b;
        a = b;
        b = sigTermino;

        printf("%d ", sigTermino);
    }
}
