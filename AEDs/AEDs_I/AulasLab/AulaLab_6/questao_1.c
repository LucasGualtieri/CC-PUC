#include <stdio.h>

int Fat(int n) {
	return n == 1 ? 1 : n * Fat(n - 1);
}

int SomaRec(int n) {
	return n == 0 ? 0 : n + SomaRec(n - 1);
}

int MultiRec(int n, int m) {
	if (m == 0) return 0;
	return m == 1 ? n : n + MultiRec(n, m - 1);
}

// int MultiRec(int n, int m) {
// 	return m == 0 ? 0 : m == 1 ? n : n + MultiRec(n, m - 1);
// }

int main(void) {
	int n, m;

	printf("Digite um número: ");
	scanf("%d", &n);

	printf("O !%d é: %d", n, Fat(n));

	printf("\nO somatório é: %d\n", SomaRec(n));

	printf("Digite um número: ");
	scanf("%d", &m);

	printf("\nA multiplicação de %d por %d é: %d", n, m, MultiRec(n, m));

	return 0;
}