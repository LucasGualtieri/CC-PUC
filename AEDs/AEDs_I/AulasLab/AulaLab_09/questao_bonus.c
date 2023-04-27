#include <stdio.h>

int main(void) {
	int vetor1[] = { 1, 2, 3, 4 };
	int arrayLength = sizeof(vetor1) / sizeof(int);
	int vetor2[arrayLength];

	for (int i = 0, k = arrayLength - 1; i < arrayLength; i++, k--) {
		vetor2[i] = vetor1[k];
		printf("%d ", vetor2[i]);
	}

	return 0;
}