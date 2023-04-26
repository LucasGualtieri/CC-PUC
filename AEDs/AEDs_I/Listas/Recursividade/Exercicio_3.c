#include <stdio.h>

/*
	Fazer um método recursivo que recebe um número
	inteiro e positivo n e calcula o somatório abaixo.
	n + (n − 1) + ... + 1 + 0
*/

int Rec(int n) {
	return n == 0 ? 0 : n + Rec(n - 1);
}

int main() {
	int n;

	printf("Digite um número *natural: ");
	scanf("%d", &n);

	printf("Somatório = %d", Rec(n));

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}