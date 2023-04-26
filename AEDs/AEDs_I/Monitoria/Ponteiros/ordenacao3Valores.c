#include "/home/lucas/CC-PUC/Bibliotecas/biblioteca_c.h"

void LeiaValor(float* x) {
	printf("DIGITE UM VALOR: ");
	scanf("%f", x);
}

void OrdenaTresValores(float* Maior, float* Meio, float* Menor, float a, float b, float c) {
	if (a > b && a > c) {
		*Maior = a;
	} else if (b > a && b > c) {
		*Maior = b;
	} else if (c > a && c > b) {
		*Maior = c;
	}

	if (a < b && a > c || a < c && a > b) {
		*Meio = a;
	} else if (b < a && b > c || b < c && b > a) {
		*Meio = b;
	} else if (c < a && c > b || c < b && c > a) {
		*Meio = c;
	}

	if (a < b && a < c) {
		*Menor = a;
	} else if (b < a && b < c) {
		*Menor = b;
	} else if (c < a && c < b) {
		*Menor = c;
	}
}

int main() {
	float a, b, c;
	float Maior, Meio, Menor;

	LeiaValor(&a);
	LeiaValor(&b);
	LeiaValor(&c);

	printf("%f,%f,%f", a, b, c);

	OrdenaTresValores(&Maior, &Meio, &Menor, a, b, c);

	// Meio();

	return 0;
}