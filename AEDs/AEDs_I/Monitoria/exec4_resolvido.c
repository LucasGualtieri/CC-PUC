#include <stdio.h>

int fatorial(int n) {
	int fat = 1;
	for (int i = 1; i <= n; i++) {
		fat *= i;
	}
	return fat;
}

int main(void) {
	// declaração
	int N;

	for (int k = 0; k < 25; k++) {
		double E = 1;
		for (int i = 1; i < k; i++) {
			E += 1.0 / fatorial(i);
		}
		printf("%.45lf\n", E);
	}

	return 0;
}