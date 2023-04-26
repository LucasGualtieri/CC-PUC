#include <stdio.h>

int main() {

	int n = 10;

	// Printa os N primeiros números b da sequência { 1, 3, 5, 7, 9,... }
	printf("{ ");
	for (int i = 1; i < n * 2; i += 2) {
		printf("%d, ", i);
	}
	printf("... }");

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}