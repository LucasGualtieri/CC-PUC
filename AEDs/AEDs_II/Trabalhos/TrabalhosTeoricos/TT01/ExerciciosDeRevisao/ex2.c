#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct IntegerArray {
	int	 size;
	int* buffer;
} IntegerArray;

void greatestLowest(IntegerArray array) {

	int greatest = INT_MIN, lowest = INT_MAX;

	for (int i = 0; i < array.size; i++) {
		if (array.buffer[i] > greatest) greatest = array.buffer[i];
		if (array.buffer[i] < lowest) lowest = array.buffer[i];
	}

	printf("Maior elemento: %d\n", greatest);
	printf("Menor elemento: %d\n", lowest);
}

int main() {
	IntegerArray array;
	array.size	 = 5;
	array.buffer = (int*)malloc(array.size * sizeof(int));

	for (int i = 0; i < 5; i++) {
		array.buffer[i] = i + 6;
	}

	greatestLowest(array);

	free(array.buffer);

	return 0;
}