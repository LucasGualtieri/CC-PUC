#include <stdio.h>

int main(void) {

	int N;
	scanf("%d", &N);

	float E = 1;
	for (int i = 1; i < N; i++) {

		int fat = 1;

		for (int j = i; j >= 2; j--) {

			fat = fat * j;
		}

		E += 1.0 / fat;
	}

	printf("%.2f", E);

	return 0;
}