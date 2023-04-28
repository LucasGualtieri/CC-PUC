#include <stdio.h>
#include <windows.h>

float MediaDeDano(int hitsHead, int hitsBody, int hitsLegs) {

   return (hitsHead * 140) + (hitsBody * 33) + (hitsLegs * 29) / (hitsHead + hitsBody + hitsLegs);
}

int main(void) {
   system("cls");
   SetConsoleOutputCP(65001);

   int n, acertosCab, acertosCorpo, acertosPerna, atleta;
   float maior = 0;

   printf("Digite o número de atletas a serem analisádos: ");
   scanf("%d", &n);

   for (int i = 0; i < n; i++) {
      printf("Atleta N°%d\n", i+1);
      printf("Números de acertos na cabeça: "), scanf("%d", &acertosCab);
      printf("Números de acertos no corpo: "), scanf("%d", &acertosCorpo);
      printf("Números de acertos na perna: "), scanf("%d", &acertosPerna);
      if (MediaDeDano(acertosCab, acertosCorpo, acertosPerna) > maior) {
         maior = MediaDeDano(acertosCab, acertosCorpo, acertosPerna);
         atleta = i+1;
      }
      printf("\n");
   }

   printf("O atleta de maior média foi o atleta N°%d!", atleta);

   printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
   return 0;
}