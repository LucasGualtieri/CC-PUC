#include <biblioteca_c.h>

bool iguais(int vetor[], int ultimo) {
	int iguais, busca = 0;
	while (busca != ultimo && (iguais = vetor[busca++] == vetor[ultimo]));
	return iguais;
}

int main() {

	int vetor[] = { 1, 1, 1, 1, 1 };

	if (iguais(vetor, arrayLength(vetor) - 1)) {
		printf("Iguais\n");
	} else {
		printf("Diferentes\n");
	}

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}