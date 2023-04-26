#include <stdio.h>

int soma(int a, int b) {
	return a + b;
}

int main(void) {
	int a, b;

	printf("Digite um número inteiro: ");
	scanf("%d", &a);

	printf("Digite um número inteiro: ");
	scanf("%d", &b);

	printf("\n%d + %d = %d", a, b, soma(a, b));

	return 0;
}