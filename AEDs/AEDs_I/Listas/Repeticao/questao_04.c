#include <math.h>
#include <stdio.h>

// Resolve a função proposta usando a função pow() e imprime apenas o enésimo número.
float ProgressaoGeometrica(int a, int q, int n) {
	return a * pow(q, (n - 1));
}

// Resolve a função proposta usando um FOR e imprime apenas o enésimo número.
float ProgressaoGeometricaSemPow(int a, int q, int n) {
	float qAux = q;

	for (int i = 1; i < (n - 1); i++) {
		qAux *= q;
	}

	return a * qAux;
}

// Resolve a função proposta usando apenas adição e imprime apenas o enésimo número.
// Não soube fazer essa questão, tive que usar pow no condição do FOR.
float ProgressaoGeometricaSemPowSemMulti(int a, int q, int n) {
	float qAux = q;

	for (int i = 1; i < pow(q, (n - 2)); i++) {
		qAux += q;
	}

	return a * qAux;
}

int main() {

	float a, q, n;

	printf("Digite o 1° termo de uma PG: ");
	scanf("%f", &a);

	printf("Digite a razão de uma PG: ");
	scanf("%f", &q);

	printf("Digite a quatidade de vezes que a PG acontecerá: ");
	scanf("%f", &n);

	printf("\nAn = A1 * Q ^ (N - 1)");
	printf("\n%.1f = %.1f * %.1f ^ (%.1f - 1)", ProgressaoGeometrica(a, q, n), a, q, n);
	printf("\n%.1f = %.1f * %.1f ^ (%.1f - 1)", ProgressaoGeometricaSemPow(a, q, n), a, q, n);
	printf("\n%.1f = %.1f * %.1f ^ (%.1f - 1)", ProgressaoGeometricaSemPowSemMulti(a, q, n), a, q, n);

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}