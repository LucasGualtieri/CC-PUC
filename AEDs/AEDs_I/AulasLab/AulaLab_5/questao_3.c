#include <stdio.h>

int math(int a, int b, int c, int resultado) {
	for (int i = b + 1; i < c; i++) {
		if (i % a == 0) {
			// printf("%d", i);
			resultado += i;
		}
	}
	return resultado;
}

int main(void) {
	int a, b, c, resultado = 0;

	do {
		printf("Digite um número inteiro > 1: ");
		scanf("%d", &a);
	} while (a <= 1);

	printf("Digite mais um número inteiro: ");
	scanf("%d", &b);

	printf("Digite um último número inteiro: ");
	scanf("%d", &c);

	printf("\n%d", math(a, b, c, resultado));

	return 0;
}