#include <stdio.h>

/* Fazer um método recursivo que imprima de um número natural em base binária */

void RecDecimalPBinario(int n) {
	if (n == 0) {
		printf("0");
	} else if (n == 1) {
		printf("1");
	} else {
		if (n % 2 == 0) {
			RecDecimalPBinario(n / 2);
			printf("0");
		} else {
			RecDecimalPBinario(n / 2);
			printf("1");
		}
	}
}

int main() {
	int n;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("O binário de %d é: ", n);

	RecDecimalPBinario(n);

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}