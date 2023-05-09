#include <biblioteca_c.h>

void alteraPonteiro(int** ponteiro, int* peso) {
	*ponteiro = peso;
	// ponteiro = &peso;
}

int main() {

	int idade = 20;
	int peso = 80;
	int* ponteiro = &idade;

	printf("Ponteiro: %d\n", *ponteiro);

	alteraPonteiro(&ponteiro, &peso);

	printf("Ponteiro: %d\n", *ponteiro);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}