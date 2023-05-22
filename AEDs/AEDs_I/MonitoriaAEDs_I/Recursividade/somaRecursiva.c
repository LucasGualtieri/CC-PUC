#include <biblioteca_c.h>

int soma(int vetor[], int primeiro, int ultimo) {
	if (primeiro == ultimo) {
		return primeiro;
	} else {
		return vetor[primeiro] + soma(vetor, primeiro++, ultimo);
	}
}

int main() {
	int tamanho = 3;
	int vetor[3] = { 1, 2, 3 };

	int primeiro = 0;
	int ultimo = tamanho - 1;
	int soma = Soma(vetor, primeiro, ultimo);

	printf("Soma: %d\n", soma);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}