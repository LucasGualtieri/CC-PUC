#include <stdio.h>
#include <windows.h>

// Imprime todos os números < N da Sequência de Fibonacci.
void fibonacci(int l) {
   int a = 0, b = 1, c = 0;

   printf("{ 0, 1, ");
   for (int i = 2; c < l; i++) {
      c = a + b;
      a = b;
      b = c;
      if (c < l) {
         printf("%d, ", c);
      }
   }
   printf("... }\n");
}

int main() {
   system("cls");
   SetConsoleOutputCP(65001);
   int l;

   printf("Valores da sequência de Fibonacci < que: ");
   scanf("%d", &l);
   fibonacci(l);

   printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
   return 0;
}