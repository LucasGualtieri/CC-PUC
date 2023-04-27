#include <stdio.h>

int main() {

	// Printa todos os múltiplos de 5 de 1 até 100.
	for (int i = 1; i <= 100; i++) {
		if (i % 5 == 0) {
			printf("%d é múltiplo de 5\n", i);
		}
	}
	printf("...\n");

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}