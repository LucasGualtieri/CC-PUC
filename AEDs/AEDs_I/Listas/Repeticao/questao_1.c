#include <stdio.h>

// Soma uma quantidade N de valores.
int soma(int n) {
	int newN, soma = 0;

	for (int i = 0; i < n; i++) {
		printf("\n%d° número: ", i + 1);
		scanf("%d", &newN);
		soma += newN;
	}
	return soma;
}

int main() {

	int n;
	printf("Números a serem lidos: ");
	scanf("%d", &n);

	printf("\nValor da soma = %d", soma(n));

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}