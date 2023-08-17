#include <stdio.h>

int main() {

	int N	 = 5;
	int cont = 0;

	for (int i = 0; i < N; i++) {
		cont += 3;
		for (int j = 0; j < N; j++) {
			cont += 2;
		}
	}

	printf("Cont: %d\n", cont);

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}