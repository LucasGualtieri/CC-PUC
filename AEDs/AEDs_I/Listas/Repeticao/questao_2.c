#include <stdio.h>
#include <windows.h>

// Imprime uma quantidade N de valores da Sequência de Fibonacci
void fibonacci(int l) {
   int a = 0, b = 1, c;
  
   printf("{ 0, 1, ");
   for (int i = 2; i < l; i++) {
      c = a + b;
      a = b;
      b = c;
      printf("%d, ", c);
   }
  printf("... }\n");
}

int main() {
   system("cls");
   SetConsoleOutputCP(65001);

   int l;
  
   printf("Qtd de números da sequência de Fibonacci: ");
   scanf("%d", &l);
   
   fibonacci(l);

   printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
   return 0;
}