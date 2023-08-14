#include <stdio.h>

void fn(int N) {
	if (N == 1) return;

	int esquerda;
	scanf("%d", &esquerda);
	fn(N - 1);
	int direita;
	scanf("%d", &direita);

	printf("%d + %d = %d\n", esquerda, direita, esquerda + direita);
}

int main() {
	int N;

	printf("Digite um número inteiro: ");
	scanf("%d", &N);

	fn(N / 2);
}