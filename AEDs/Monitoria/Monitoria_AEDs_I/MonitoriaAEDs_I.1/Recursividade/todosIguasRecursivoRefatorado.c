#include <biblioteca_c.h>

bool Iguais(int* vetor, int comeco, int fim) {

	if (comeco >= fim) return true;

	return (vetor[comeco] == vetor[fim]) ? Iguais(vetor, ++comeco, --fim) : false;
}

bool IguaisIterativo(int primeiro, int ultimo, int vetor[]) {
	while (primeiro < ultimo) {
		if (vetor[primeiro] != vetor[ultimo]) {
			return false;
		}
		primeiro++;
		ultimo--;
	}
	return true;
}

bool IguaisRecursivo(int primeiro, int ultimo, int* vetor) {
	if (primeiro < ultimo) {
		if (vetor[primeiro] != vetor[ultimo]) {
			return false;
		}
		IguaisRecursivo(primeiro + 1, ultimo - 1, vetor);
	}
	return true;
}

// bool IguaisRecursivo(int primeiro, int ultimo, int* vetor) {

// 	if (primeiro < ultimo) {
// 		if (vetor[primeiro] != vetor[ultimo]) {
// 			return false;
// 		}
// 		return IguaisRecursivo(++primeiro, --ultimo, vetor);
// 	}

// 	return true;
// }

int main() {
	int vetor[] = { 3, 3, 3, 3 };

	int primeiro = 0, ultimo = arrayLength(vetor) - 1;

	if (IguaisIterativo(primeiro, ultimo, vetor)) {
		printf("Todos os números são iguais\n");
	} else {
		printf("Nem todos os números são iguais\n");
	}

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}