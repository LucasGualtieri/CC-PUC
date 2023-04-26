#include <math.h>
#include <stdio.h>

int main(void) {
	float a, b, divisao;

	printf("Variável A: ");
	scanf("%f", &a);
	printf("Variável B: ");
	scanf("%f", &b);

	if (b == 0) {
		printf("\nNão é possível dividir por zero");
	} else {
		divisao = a / b;
		printf("\n%.2f / %.2f = %.2f", a, b, divisao);
	}

	return 0;
}