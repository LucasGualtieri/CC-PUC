#include <stdio.h>

// Essa função recebe um número inteiro n e retorna ->
// o maior elemento da sequência de Fibonacci que seja menor que n.
int fibonacci(int n) {
	int a = 0, b = 1, c, res = 0;

	for (int i = 1; i < n; i++) {
		res = c;
		c	= a + b;
		a	= b;
		b	= c;
		if (c >= n) return res;
	}

	return c;
}

// Esse procedimento lê o valor de n e chama a função.
void ExercicioXIV() {
	int n;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("%d é o maior elemento da sequência de Fibonacci < que %d", fibonacci(n), n);
}

int main() {

	ExercicioXIV();

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}