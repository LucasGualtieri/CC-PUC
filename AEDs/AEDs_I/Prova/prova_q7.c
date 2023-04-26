#include <stdio.h>
#include <windows.h>

int main(void) {
   system("cls");
   SetConsoleOutputCP(65001);

   int n, soma = 0, somaPar = 0, cont = 0, contImp = 0, maior = 0, menor = 30000;
   float media, mediaPar, percent;

   do {
      printf("Digite um número natural: ");
      scanf("%d", &n);

      if (n >= 0 && n < 30000) {
         soma += n;
         cont++;
         if (n > maior) maior = n;
         if (n < menor) menor = n;
         if (n % 2 != 0) {
            contImp++;
         } else {
            somaPar += n;
         }
      } else if (n < 0 || n > 30000) {
         printf("\nNúmero inválido");
      }
   } while (n != 30000);
   
   media = (float)soma / cont;
   mediaPar = (float)somaPar / (cont - contImp);
   percent = (contImp * 100.0) / (float)cont;

   printf("\nSoma: %d", soma);
   printf("\nQuantidade: %d", cont);
   printf("\nMédia: %.2f", media);
   printf("\nMaior: %d", maior);
   printf("\nMenor: %d", menor);
   printf("\nMédia dos números pares: %.2f", mediaPar);
   printf("\nPorcentagem de números ímpares: %.2f%%", percent);

   printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
   return 0;
}