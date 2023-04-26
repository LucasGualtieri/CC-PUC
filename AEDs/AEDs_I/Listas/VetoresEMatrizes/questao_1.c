#include "/home/lucas/CC-PUC/Bibliotecas/biblioteca_c.h"

void ArrayFillRand(int* array, int arrayLength, int minRange, int maxRange) {

	srand(time(NULL));
	for (int i = 0; i < arrayLength; i++) {
		array[i] = (rand() % ((maxRange + 1) - minRange)) + minRange;
		srand(rand());
	}
}

void CalculaMedia(int* array, int arrayLength) {
	int i, alunosAcimaDaMedia = 0, soma = 0;
	float media;

	for (i = 0; i < arrayLength; i++) {
		soma += array[i];
	}

	media = (float)soma / i;

	for (i = 0; i < arrayLength; i++) {
		if (array[i] >= 6) alunosAcimaDaMedia++;
	}

	printf("Média da Turma: %g\n", media);
	printf("Alunos acima da média: %d\n", alunosAcimaDaMedia);
}

int main() {

	int notasAlunos[10];

	ArrayFillRand(notasAlunos, arrayLength(notasAlunos), 0, 10);
	IntVetorCrescente(notasAlunos, arrayLength(notasAlunos));
	IntArrayPrint(notasAlunos, arrayLength(notasAlunos));
	CalculaMedia(notasAlunos, arrayLength(notasAlunos));

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}