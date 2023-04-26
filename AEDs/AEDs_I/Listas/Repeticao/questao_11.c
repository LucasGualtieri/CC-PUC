#include <stdio.h>
#include <windows.h>

int main() {
   system("cls");
   SetConsoleOutputCP(65001);

   int n = 30;

   // Printa os números divisíveis por três e múltiplos de cinco...->
   // -> ou divisíveis por sete da sequência { 1, 3, 5, 7, 9,... }
   printf("{ ");
   for (int i = 1; i < n * 2; i += 2) {
      if (i % 3 == 0 && i % 5 == 0 || i % 7 == 0) {
         printf("%d, ", i);
      }
   }
   printf("... }");

   printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
   return 0;
}