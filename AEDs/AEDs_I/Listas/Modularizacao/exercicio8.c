#include <stdio.h>

// Essa função recebe um número inteiro n e retorna seu fatorial (!n).
double fat(int n) {
	return n == 1 ? 1 : n * fat(n - 1);
}

// Esse procedimento lê o valor de n e chama a função.
void Exercicio08() {
	int n;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("O fatorial de %d é: %lf", n, fat(n));
}

int main() {

	Exercicio08();

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}