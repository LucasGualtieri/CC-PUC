#include <stdio.h>
#include <windows.h>

// Essa fução processa toda a lógica relevante do programa.
void Procedimento(int alunos, int provas) {
   int nota = 0, somaGeral = 0;
   float  mediaGeral = 0, excelencia = 0;

   // Esse FOR rodará 'numAlunoS' vezes.
   for (int i = 0; i < alunos; i++) {
      int somaAluno = 0;
      float mediaAluno = 0;

      // Esse FOR rodará 'numProva' vezes.
      for (int j = 0; j < provas; j++) {
         printf("\nAluno n°%d - prova n°%d: ", (i+1), (j+1));
         scanf("%d", &nota);

         if (nota < 0 || nota > 10) {
            do {
               printf("\nAluno n°%d - prova n°%d (Min - 0 | Max - 10): ", (i+1), (j+1));
               scanf("%d", &nota);
            } while (nota < 0 || nota > 10);
         }

         somaAluno += nota;
      }
      mediaAluno = somaAluno / (float)provas;
      somaGeral += somaAluno;

      // Esse IF conta a quantidade de alunos com média > 80%.
      if (mediaAluno >= 8) {
         excelencia++;
      }

      printf("\nA média do aluno n°%d é: %.1f\n", (i+1), mediaAluno);
      printf("\n-----------------------------\n");
   }

   mediaGeral = somaGeral / ((float)provas * alunos);
   printf("\nA média Geral é: %.1f", mediaGeral);

   printf("\n%.1f%% dos alunos obtiveram média > 80%%", ((excelencia / alunos) * 100));
}

int main() {
   system("cls");
   SetConsoleOutputCP(65001);

   int alunos, provas;

   printf("\nNúmero de alunos: ");
   scanf("%d", &alunos);

   printf("Número de provas: ");
   scanf("%d", &provas);

   Procedimento(alunos, provas);

   printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
   return 0;
}