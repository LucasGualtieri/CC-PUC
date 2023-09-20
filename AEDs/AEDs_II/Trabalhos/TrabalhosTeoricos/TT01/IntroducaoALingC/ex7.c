#include <stdio.h>

int main() {
	int N;

	printf("Digite um número inteiro: ");
	scanf("%d", &N);

	FILE* file = fopen("ex999.txt", "w");

	for (int i = 0; i < N; i++) {
		int inteiro;
		printf("%d° inteiro: ", i + 1);
		scanf("%d", &inteiro);
		fprintf(file, "%d ", inteiro);
	}

	fclose(file);
	file = fopen("ex999.txt", "r");

	for (int i = 0; i < N; i++) {
		int inteiro;
		fscanf(file, "%d", &inteiro);
		printf("%d° inteiro: %d\n", i + 1, inteiro);
	}
}