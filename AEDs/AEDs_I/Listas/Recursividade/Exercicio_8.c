#include <stdio.h>

/* Fazer um método recursivo que determine se um número é ou não primo. */

int isPrime(int n, int nAux) {
	if (n == 1) return 0;
	if (nAux < 2) return 1;
	return (n % nAux == 0) ? 0 : isPrime(n, --nAux);
}

int main() {
	int n = 1;

	printf("Digite 0 para interromper o programa\n");

	while (n != 0) {
		printf("Digite um número: "), scanf("%d", &n);

		if (n == 0) break;

		printf("O número %d %s", n, isPrime(n, n - 1) == 1 ? "é primo" : "não é primo");
		printf("\n\n");
	}

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}