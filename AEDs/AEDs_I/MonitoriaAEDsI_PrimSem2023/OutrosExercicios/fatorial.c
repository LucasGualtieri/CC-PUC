#include <biblioteca_c.h>

int fatorial(int n) {
	if (n == 0) return 1;

	int fat = n;
	for (int i = n; i > 1; i--) {
		fat = fat * (i - 1);
	}

	return fat;
}

int main() {

	int n = 0;
	printf("O fatorial de %i é %i\n", n, fatorial(n));

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}