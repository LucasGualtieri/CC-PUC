#include <stdbool.h>
#include <stdio.h>

/* Fazer um método recursivo que determine se um número é ou não primo. */

int isPrime(int n, int nAux) {
	if (n == 1 || n == 0) return false;
	if (nAux == 2) return true;
	return (n % --nAux == 0) ? false : isPrime(n, nAux);
}

int main() {

	int n, nAux;

	printf("Digite um número: "), scanf("%d", &n);

	printf("O número %d %s\n", n, isPrime(n, n) == 1 ? "é primo" : "não é primo");

	// for (int i = 0; i < 100; i++) {
	// 	if (isPrime(i, i)) {
	// 		printf("O número %d %s\n", i, "é primo");
	// 	}
	// }

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}