#include <stdio.h>

int main() {

	int soma = 0;
	for (int i = 1; i <= 10; soma += i++) { continue; }

	printf("Soma: %d\n", soma);

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}