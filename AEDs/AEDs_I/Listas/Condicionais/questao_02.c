#include <stdio.h>

int main(void) {
	int a, b, soma;

	printf("Variável A: ");
	scanf("%d", &a);
	printf("Variável B: ");
	scanf("%d", &b);

	soma = a + b;
	if (soma >= 10) {
		soma += 5;
		printf("\nA soma de (%d + %d) + 5 = %d", a, b, soma);
	} else {
		soma += 7;
		printf("\nA soma de (%d + %d) + 7 = %d", a, b, soma);
	}

	return 0;
}