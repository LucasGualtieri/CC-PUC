#include <biblioteca_c.h>

int MaiorNumeroIterativo(int* vetor, int size) {
	int maior = INT_MIN;

	for (int i = 0; i < size; i++) {
		if (vetor[i] > maior) maior = vetor[i];
	}

	return maior;
}

int MaiorNumero(int* vetor, int size, int i) {
	int maior = vetor[i];

	if (i < size) {
		int proximo_maior = MaiorNumero(vetor, size, i + 1);
		if (maior < proximo_maior) {
			maior = proximo_maior;
		}
	}

	return maior;
}

int main() {

	int vetor[] = { 1, 20, 9, 4, 5 };
	int size = sizeof(vetor) / sizeof(int);

	// int resultado = MaiorNumero(vetor, size - 1, -Infinity);
	int resultado = MaiorNumero(vetor, size, 0);

	printf("Resultado: %d\n", resultado);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}