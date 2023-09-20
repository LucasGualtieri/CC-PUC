#include <math.h>
#include <stdio.h>

int somatorioPA(double a, double b, int n) {
	double soma = 0;
	for (int i = 0; i <= n; i++) {
		soma += a + b * i;
	}

	return soma;
}

int main() {
	double a = 0, b = 1;
	int	   n = 5;

	printf("PA(a = %lf, b = %lf, n = %d) = %d\n", a, b, n, somatorioPA(a, b, n));
}