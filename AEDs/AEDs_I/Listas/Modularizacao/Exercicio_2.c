#include <stdio.h>

int par(int n) {
	return n * 2;
}

void mostrarParesEmOrdemDecrescente(int n) {
	printf("\n{");
	for (int i = par(n); i >= 0; i -= 2) {

		printf(" %d", i);
		if (i != 0) printf(",");
	}
	printf(" }");
}

void Exercicio02(int n) {
	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	mostrarParesEmOrdemDecrescente(n);
}

int main() {
	int n;

	Exercicio02(n);

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}