#include <stdio.h>

#define arraySize(array) (int)(sizeof(array) / sizeof(array[0]))

int palin_aux(int* array, int right, int left) {

	if (right <= left) {
		if (array[right] != array[left]) {
			return 0;
		} else {
			return palin_aux(array, right + 1, left - 1);
		}
	}

	return 1;
}

int palin(int* array, int size) {
	return palin_aux(array, 0, size - 1);
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};

	printf("%s\n", palin(array, arraySize(array)) ? "SIM" : "NAO");
}