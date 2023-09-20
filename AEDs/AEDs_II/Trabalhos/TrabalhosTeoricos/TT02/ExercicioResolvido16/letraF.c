#include <stdio.h>

int main() {

	int N	 = 16;
	int cont = 0;

	for (int i = N; i > 1; i /= 2) {
		cont++;
		cont += 5;
	}

	printf("Cont: %d\n", cont);

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}