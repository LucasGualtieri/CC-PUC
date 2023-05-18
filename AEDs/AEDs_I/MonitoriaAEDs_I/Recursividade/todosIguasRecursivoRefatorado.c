#include <biblioteca_c.h>

bool Iguais(int* vetor, int comeco, int fim) {

	if (comeco >= fim) return true;

	return (vetor[comeco] == vetor[fim]) ? Iguais(vetor, ++comeco, --fim) : false;
}

int main() {
	int vetor[] = { 3, 3, 3, 3 };

	if (Iguais(vetor, 0, arrayLength(vetor) - 1)) {
		printf("Todos os números são iguais\n");
	} else {
		printf("Nem todos os números são iguais\n");
	}

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}