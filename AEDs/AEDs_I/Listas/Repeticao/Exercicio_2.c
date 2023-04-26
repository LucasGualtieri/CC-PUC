#include <stdio.h>

void fibonacci(int l) {
	int a = 0, b = 1, c;

	printf("{ 0, 1, ");
	for (int i = 2; i < l; i++) {
		c = a + b;
		a = b;
		b = c;
		printf("%d, ", c);
	}
	printf("... }\n");
}

int main(void) {
	int l;

	printf("Qtd de números da sequência de Fibonacci: ");
	scanf("%d", &l);
	fibonacci(l);

	return 0;
}