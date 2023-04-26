#include <stdio.h>

void isPositive(int n) {
	if (n > 0) {
		printf("Número positivo");
	} else {
		printf("Número negativo");
	}
}

int main(void) {
	int n;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	isPositive(n);

	return 0;
}