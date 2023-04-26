#include <stdio.h>
#include <windows.h>

int main() {
   system("cls");
   SetConsoleOutputCP(65001);

   int n = 30, a, b;

   printf("Digite um número inteiro: "), scanf("%d", &a);
   printf("Digite um outro número inteiro: "), scanf("%d", &b);

   // Printa os números > a e < b da sequência { 1, 3, 5, 7, 9,... }
   printf("{ ");
   for (int i = 1; i < n * 2; i += 2) {
      if (i > a && i < b) {
         printf("%d, ", i);
      }
   }
   printf("... }");

   printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
   return 0;
}