#include <stdio.h>
#include <windows.h>

int main(void) {
   system("cls");
   SetConsoleOutputCP(65001);

   int N = 4, i = 0, j = 1;
   float resultado = 0;

   for (int cont = 0; cont < N; cont++) {
      i += 2;
      resultado += i / (float)j;
      printf("\nresultado: = %f", resultado);
      j *= 2;
   }

   printf("\nresultado: = %f", resultado);

   // while(contador < N) {
   //    i += 2;
   //    resultado = resultado + ((float)i / (float)j);
   //    printf("\nresultado: = %f", resultado);
   //    j *= 2;
   //    contador++;
   // }


   printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
   return 0;
}