#include <stdio.h>

#define arraySize(array) (int)(sizeof(array) / sizeof(array[0]))

// arrayPrint para inteiros
void IntArrayPrint(int* array, int arrayLength) {
	printf("{ ");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d", array[i]);
		printf("%s", i < arrayLength - 1 ? ", " : " }\n");
	}
}

void sort_aux(int* array, int size, int minIndex, int i, int j) {

	if (j < size) {
		if (array[minIndex] > array[j]) {
			minIndex = j;
		}
		if (++j < size) {
			sort_aux(array, size, minIndex, i, j);
		}
	}

	if (i < size - 1 && j == size) {
		int swap		= array[minIndex];
		array[minIndex] = array[i];
		array[i]		= swap;

		if (++i < size - 1) {
			sort_aux(array, size, i, i, i + 1);
		}
	}
}

void sort(int* array, int size) {
	sort_aux(array, size, 0, 0, 1);
}

int main() {
	int array[] = {865, -318, -786, 495, -228};

	int size = arraySize(array);

	IntArrayPrint(array, size);

	sort(array, size);

	IntArrayPrint(array, size);
}