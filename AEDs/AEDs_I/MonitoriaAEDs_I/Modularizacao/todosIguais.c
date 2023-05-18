#include <biblioteca_c.h>

bool iguais(int vetor[], int ultimo) {
	bool iguais;
	for (int i = 0; (iguais = (vetor[i++] == vetor[ultimo]) && i != ultimo); i++) { }
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