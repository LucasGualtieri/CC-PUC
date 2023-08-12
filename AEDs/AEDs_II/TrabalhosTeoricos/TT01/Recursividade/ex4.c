#include <stdio.h>

int greatest(int* array, int size) {

	if (size > 1) {
		int aux = greatest(array, size - 1);
		return array[size] > aux ? array[size] : aux;
	}

	if (array[size] > array[size - 1]) {
		return array[size];
	} else {
		return array[size - 1];
	}
}

int main() {

	int array[] = {-912, 370, 999, -295, -71};

	printf("The greatest element of the array is: ");
	printf("%d\n", greatest(array, 5));
}