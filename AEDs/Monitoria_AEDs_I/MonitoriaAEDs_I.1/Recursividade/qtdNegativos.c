#include <biblioteca_c.h>

int Negativos(int vetor[], int ultimo, int negativos) {

	if (ultimo > 0) {
		if (vetor[ultimo] < 0) {
			return Negativos(vetor, ultimo - 1, negativos + 1);
		} else {
			return Negativos(vetor, ultimo - 1, negativos);
		}
	}

	return negativos;
}

int main() {

	int vetor[] = { 1, 2, 3, -4, -5 };
	int tamanho = 5;

	int negativos = Negativos(vetor, tamanho - 1, 0);

	printf("Negativos: %d\n", negativos);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}