#include <stdio.h>

void dobro(int* a, int* b) {
	*a *= 2;
	*b *= 2;
}

int main(void) {
	int a, b;

	printf("Digite um valor para A: ");
	scanf("%d", &a);

	printf("Digite um valor para B: ");
	scanf("%d", &b);

	dobro(&a, &b);

	printf("A: %d", a);
	printf("\nB: %d", b);

	return 0;
}