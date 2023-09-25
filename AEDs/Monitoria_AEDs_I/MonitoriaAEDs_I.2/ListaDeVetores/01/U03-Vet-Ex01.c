#include <stdio.h>

int main() {
	int vetorSize = 10;

	int vetor[vetorSize];

	printf("Digite %d números para serem armazenados.\n", vetorSize);

	for (int i = 0; i < vetorSize; i++) {
		printf("%d° número: ", i + 1);
		scanf("%d", &vetor[i]);
	}

	printf("{ ");
	for (int i = 0; i < vetorSize; i++) {
		printf("%d ", vetor[i]);
	}
	printf("}");

	return 0;
}