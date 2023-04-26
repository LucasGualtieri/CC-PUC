#include <stdio.h>

int main() {

	int i;
	float r;

	printf("Digite um número inteiro: "), scanf("%d", &i);
	printf("Digite um número real: "), scanf("%f", &r);

	// Decrementa I equanto i > 10
	while (i > 10) {
		printf("I = %d\n", i);
		i--;
	}

	printf("\n----------------\n\n");

	// Incrementa R equanto R < 10
	while (r < 10) {
		printf("I = %.1f\n", r);
		r++;
	}

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}