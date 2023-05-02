#include <biblioteca_c.h>

int fibonacci(int n) {
	if (n <= 1) return n;

	int primeiroTermo = 0, segundoTermo = 1;

	for (int i = 1; i < n; i++) {
		int temp = segundoTermo;
		segundoTermo = primeiroTermo + segundoTermo;
		primeiroTermo = temp;
	}

	return segundoTermo;
}

int function(int nth, int boolean) {
	for (int i = 1, contador = 0; true; i++) {
		if (boolean % 2 == 0) {
			if (fibonacci(i) % 2 == 0) {
				if (++contador == nth) {
					return fibonacci(i);
				}
			}
		} else {
			if (fibonacci(i) % 2 != 0) {
				if (++contador == nth) {
					return fibonacci(i);
				}
			}
		}
	}
	return 0;
}

int main() {

	int N = 5;

	printf("O %d° termo de Fibonacci é %d\n", N, fibonacci(N));

	for (int i = 1; i <= N; i++) {
		printf("%d ", fibonacci(i));
	}

	printf("\n");

	printf("%'d\n", function(3, 0));

	return 0;
}