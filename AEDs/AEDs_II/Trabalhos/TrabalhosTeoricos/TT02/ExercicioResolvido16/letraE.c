#include <stdio.h>

int main() {

	int N	 = 5;
	int cont = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cont += 2;
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					cont += 2;
				}
			}
		}
		if (i % 2 == 0) cont++;
	}

	printf("Cont: %d\n", cont);

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}