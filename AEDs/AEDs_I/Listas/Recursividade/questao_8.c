#include <stdio.h>

/* Fazer um método recursivo que determine se um número é ou não primo. */

int isPrime(int n, int nAux) {
	if (n == 1) return 0;
	if (nAux < 2) return 1;
	return (n % nAux == 0) ? 0 : isPrime(n, --nAux);
}

int main() {

	int n, nAux;

	printf("Digite um número: "), scanf("%d", &n);

	printf("O número %d %s", n, isPrime(n, n) == 1 ? "é primo" : "não é primo");

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}