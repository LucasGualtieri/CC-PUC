#include <biblioteca_c.h>

bool Iguais(int vetor[], int busca, int ultimo) {

	if (busca < ultimo) { // Se ele não chegou no fim, faça...
		if (vetor[busca] != vetor[ultimo]) {
			return false;
		} else {
			return Iguais(vetor, busca + 1, ultimo);
		}
	} else {
		return true; // Condição de parada
	}
}

int main() {
	int tamanho = 3;
	int vetor[3] = { 1, 1, 2 };

	int ultimo = tamanho - 1;
	int busca = 0; // O vetor começa no 0, então começamos a busca no começo

	bool iguais = Iguais(vetor, busca, ultimo); // Retorna true se todos forem iguais

	if (iguais == true) {
		printf("Iguais\n");
	} else {
		printf("Diferentes\n");
	}

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}