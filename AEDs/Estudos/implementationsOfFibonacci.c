#include "/home/lucas/AEDsII/Bibliotecas/biblioteca_c.h"

int fibonacciRecursivo(int n) { // Retorna o N-ésimo termo de Fibonacci
	if (n <= 1) return n;

	return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

int fibonacciVetorIterativo(int n) { // Retorna o N-ésimo termo de Fibonacci
	if (n <= 1) return n;

	int fibonacci[2] = { 0, 1 };

	for (int i = 1; i < n; i++) {
		int temp = fibonacci[1];
		fibonacci[1] = fibonacci[0] + fibonacci[1];
		fibonacci[0] = temp;
	}

	return fibonacci[1];
}

int fibonacciIterativo(int n) { // Retorna o N-ésimo termo de Fibonacci
	if (n <= 1) return n;

	int primeiroTermo = 0, segundoTermo = 1;

	for (int i = 1; i < n; i++) {
		int temp = segundoTermo;
		segundoTermo = primeiroTermo + segundoTermo;
		primeiroTermo = temp;
	}

	return segundoTermo;
}

int fibonacciIterativoAlternative(int n) {

	if (n < 1) return 0;

	int primeiroTermo = 0, segundoTermo = 1, fib;

	for (int i = 1; i < n; i++) {
		if (i < 1) {
			fib = i;
		} else {
			fib = segundoTermo;
			segundoTermo = primeiroTermo + segundoTermo;
			primeiroTermo = fib;
		}
	}

	return segundoTermo;
}

int main() {
	int n = 5;

	printf("O %d° termo de Fibonacci é: %d\n", n, fibonacciRecursivo(n));
	printf("O %d° termo de Fibonacci é: %d\n", n, fibonacciVetorIterativo(n));
	printf("O %d° termo de Fibonacci é: %d\n", n, fibonacciIterativo(n));
	printf("O %d° termo de Fibonacci é: %d\n", n, fibonacciIterativoAlternative(n));

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}