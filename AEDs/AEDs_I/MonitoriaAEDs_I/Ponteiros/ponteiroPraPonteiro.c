#include <biblioteca_c.h>

void alteraOPonteiro(int** ponteiro, int* peso) {
	*ponteiro = peso;
}

int main() {

	int idade = 20;
	int peso = 80;
	int* ponteiro = &idade;

	printf("Ponteiro: %d\n", *ponteiro);

	alteraOPonteiro(&ponteiro, &peso);

	printf("Ponteiro: %d\n", *ponteiro);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}