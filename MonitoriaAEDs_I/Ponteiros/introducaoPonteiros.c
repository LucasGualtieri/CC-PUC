#include <biblioteca_c.h>

void funcao(int* ptrIdade) {
	*ptrIdade = 20;
}

int main() {

	// Ponteiro é uma variável que armazena endereço de memória
	int idade;
	funcao(&idade);
	printf("Idade: %d\n", idade);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}