#include <stdio.h>

// clear && gcc BitwiseOperations.c && ./a.out

int main() {

	int bin = 0b111;
	bin = ~bin + 1; // Complemento de 2
	// bin &= 0b101;
	// bin = bin & 0b1;
	// bin = 0b1 & 0b1;

	printf("bin: %d\n", bin);

	return 0;
}