#include <stdbool.h>
#include <stdio.h>

#define size 2

float Calcule(int turma[size][size]) {
	int somaDasProvas = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			somaDasProvas += turma[i][j];
		}
	}

	return somaDasProvas / (size * size);
}

int main() {

	int matriz[size][size] = { { 5, 7 }, { 4, 8 } };

	printf("A média dos alunos é: %g\n", Calcule(matriz));

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}