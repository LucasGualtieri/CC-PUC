#include <stdio.h>

void Soma(int* a, int b);

int main(void) {
	int a, b;

	printf("Digite dois números inteiros separados por espaços: ");
	scanf("%d %d", &a, &b);

	printf("A: %d\nB: %d\n", a, b);

	Soma(&a, b);

	printf("%d + %d = %d", a - b, b, a);

	return 0;
}

void Soma(int* a, int b) {
	*a += b;
}