#include <stdio.h>

/* Fazer um método recursivo que recebe um número inteiro e retorna o seu fatorial. */

int Fat(int n) {
	return n == 1 ? 1 : n * Fat(n - 1);
}

int main() {

	int n;

	printf("Digite um número: ");
	scanf("%d", &n);

	printf("O !%d é: %d", n, Fat(n));

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}