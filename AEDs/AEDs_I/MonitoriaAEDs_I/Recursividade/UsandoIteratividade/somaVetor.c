#include <biblioteca_c.h>

int Soma(int vetor[], int tamanho) {
	int soma = 0;

	int i = 0;
	while (i < tamanho) {
		soma += vetor[i];
		i++;
	}

	return soma;
}

int SomaRecursiva(int vetor[], int tamanho, int i) {
	int soma = 0;

	if (i < tamanho) {
		soma += vetor[i] + SomaRecursiva(vetor, tamanho, i + 1);
	}

	return soma;
}

int main() {

	int tamanho = 3;
	int vetor[] = { 1, 2, 3 };

	// int soma = Soma(vetor, tamanho);
	// int soma = SomaVetor(vetor, tamanho);
	int soma = SomaRecursiva(vetor, tamanho, 0);

	printf("soma: %d\n", soma);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}