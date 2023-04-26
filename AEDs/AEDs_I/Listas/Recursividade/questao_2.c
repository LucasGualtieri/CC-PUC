#include <math.h>
#include <stdio.h>

/*
	Fazer um método recursivo que recebe um número inteiro n
	e retorna o n-ésimo termo da equação de recorrência abaixo:
	T(1) = 2
	T(2) = 3
	T(n) = 5 ∗ n + T(n − 1)^n
*/

// Eu concordo, essa alternativa aqui é coisa de maníaco do ternário...
// int Rec(int n) {
// 	return (n == 1) ? 2 : (n == 2) ? 3 : 5 * n + pow(Rec(n - 1), n);
// }

// int Rec(int n) {
// 	if (n == 1 || n == 2) return n + 1;

// 	return 5 * n + pow(Rec(n - 1), n);
// }

int Rec(int n) {
	return (n == 1 || n == 2) ? n + 1 : 5 * n + pow(Rec(n - 1), n);
}

int main() {

	int n;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("O %d termo da equação é: %d", n, Rec(n));

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}