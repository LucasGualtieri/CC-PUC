#include <stdio.h>

// Essa função recebe um número inteiro n e retorna o n-ésimo termo da sequência de Fibonacci.
int fibonacci(int n) {
	int a = 0, b = 1, c;

	for (int i = 2; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

// Esse procedimento lê o valor de n e chama a função.
void ExercicioXIII() {
	int n;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("O %d° termo da sequência de Fibonacci é: %d", n, fibonacci(n));
}

int main() {

	ExercicioXIII();

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}