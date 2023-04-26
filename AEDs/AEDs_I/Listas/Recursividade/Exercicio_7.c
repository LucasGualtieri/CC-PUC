#include <stdio.h>

/* Fazer um método recursivo que conte os dígitos de um determinado número. */

int contagem(int n) {
	int cont = 1;

	return (n / 10 > 0) ? cont += contagem(n / 10) : 1;
}

int main() {
	int n;

	printf("Digite um número: ");
	scanf("%d", &n);

	printf("O número de dígitos do número %d é %d", n, contagem(n));

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}

// Todas as alternativas das funções abaixo retornam o número certo de digitos de N.

/*
	int contagem(int n) {
		int cont = 0;

		if (n / 10 > 0) cont = contagem(n / 10);
		cont++;

		return cont;
	}
*/

/*
	int contagem(int n) {
		int cont = 1;

		if (n / 10 > 0) cont += contagem(n / 10);

		return cont;
	}
*/

/*
	int contagem(int n) {
		int cont = 1;

		if (n / 10 > 0) return cont += contagem(n / 10);
		return 1;
	}
*/

/* Essa eu peguei da internet pra ver como outras pessoas fizeram.
	int contagem(int n) {
		int cont = 1;
		if (n >= 10) {
			n = n / 10;
			cont += contagem(n);
		}
		return cont;
	}
*/