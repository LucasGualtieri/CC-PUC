#include <stdio.h>

void fn(int N) {
	if (N == 0) return;

	int inteiro;
	scanf("%d", &inteiro);
	fn(N - 1);
	printf("%d ", inteiro);
}

int main() {
	int N;

	printf("Digite um número inteiro: ");
	scanf("%d", &N);

	fn(N);
}