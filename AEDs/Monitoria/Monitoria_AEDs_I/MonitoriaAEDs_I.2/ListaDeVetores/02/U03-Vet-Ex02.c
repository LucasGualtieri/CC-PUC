#include <stdio.h>
// #include <math.h>

int main() {
	int vetorSize = 10;

	int vetor[vetorSize];

	for (int i = 0; i < vetorSize; i++) {	
		if (i % 2 == 0) {
			vetor[i] = i * i;
			// vetor[i] = pow(i, 2);
		} else {
			vetor[i] = i * i * i;
			// vetor[i] = pow(i, 3);
		}
		// vetor[i] = i % 2 == 0 ? i * i : i * i * i;
		// vetor[i] = pow(i, i % 2 == 0 ? 2 : 3);
	}

	printf("{ ");
	for (int i = 0; i < vetorSize; i++) {
		printf("%d ", vetor[i]);
	}
	printf("}\n");

	return 0;
}