#include <stdio.h>

void fibonacci(int l) {
	int array[l];
	array[0] = 0;
	array[1] = 1;

	printf("{ 0, 1, ");

	for (int i = 2; i < l; i++) {
		array[i] = array[i - 2] + array[i - 1];
		printf("%d, ", array[i]);
	}

	printf("... }\n");
}

int main(void) {
	int l = 10;

	printf("Qtd de números da sequência de Fibonacci: ");
	scanf("%d", &l);

	fibonacci(l);
	return 0;
}