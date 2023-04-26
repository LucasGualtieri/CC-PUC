#include <stdio.h>

int par(int n) {
	return n * 2;
}

void Exercicio01(int n) {
	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("\nO n-ésimo termo da sequência é: %d", par(n));
}

int main() {
	int exercicio, n;

	Exercicio01(n);

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}