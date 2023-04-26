#include "/home/lucas/CC-PUC/Bibliotecas/biblioteca_c.h"

int potenciacao(int base, int expo) {
	int pot = base;

	for (int i = 0; i < expo - 1; i++) {
		pot *= base;
	}

	return pot;
}

int main() {

	printf("%i potenciacao\n", potenciacao(2, 4));

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}