#include <stdio.h>

/*
	Essa função recebe um número inteiro n e retorna o
	n-ésimo termo da sequência { 2, 4, 6, 8, 10, 12... }
	ou seja, uma função que retorna o n-ésimo par.
*/

int par(int n) {
	return n * 2;
}

int parIterativo(int n) {
	int par = 0;

	for (int i = 0; i < n; i++) {
		par += 2;
	}

	return par;
}

// Esse procedimento lê o valor de n e chama a função.
void Exercicio01() {
	int n;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("\nO %d° termo da sequência é: %d", n, par(n));
}

int main() {

	Exercicio01();

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}