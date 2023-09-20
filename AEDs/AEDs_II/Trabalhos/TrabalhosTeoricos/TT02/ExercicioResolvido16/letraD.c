#include <stdio.h>

int main() {

	int N	 = 5;
	int cont = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cont += 2;
			}
		}
	}

	cont += 5;

	printf("Cont: %d\n", cont);

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}