#include <stdio.h>
#include <stdlib.h>

// Leer 2 números; si son iguales que los multiplique, si el
// primero es mayor que el segundo que los reste y
// si no que los sume.

int main()
{
   int n1 = 0, n2 = 0, r = 0;
   printf("Introduzca un numero: ");
   scanf("%i", &n1);

   printf("Introduzca el segundo numero: ");
   scanf("%i", &n2);

   if (n1 == n2)
   {
      r = n1 * n2;
      printf("n1 * n2 = %i", r);
   }
   else if (n1 > n2)
   {
      r = n1 - n2;
      printf("n1 - n2 = %i", r);
   }
   else
   {
      r = n1 + n2;
      printf("n1 + n2 = %i", r);
   }

   return 0;
}
