#include <stdio.h>

int main(void) {
	float a, b, x, resultado;
	scanf("%f %f %f", &a, &x, &b);

	resultado = a * x + b;
	printf("%.2f", resultado);
	return 0;
}