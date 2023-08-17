#include <stdio.h>

int main() {

	int N	 = 5;
	int cont = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cont += 5;
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					cont += 9;
				}
			}
		}
	}

	for (int i = 0; i < N / 2; i++) {
		cont++;
	}

	printf("Cont: %d\n", cont);

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}