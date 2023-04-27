#include <stdio.h>

int main(void) {
	float a, b;

	printf("Variável A: ");
	scanf("%f", &a);
	printf("Variável B: ");
	scanf("%f", &b);

	if ((a - b) < 0) { // if (a < b)
		printf("\nVariável B é a maior variável");
	} else {
		printf("\nVariável A é a maior variável");
	}

	return 0;
}