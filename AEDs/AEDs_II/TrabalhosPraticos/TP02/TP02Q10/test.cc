#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <stdio.h>
#include <string.h>
#include <string>
#include <thread>
#include <vector>

#define arrayLength(array) (sizeof(array) / sizeof(array[0]))

using namespace std;

// ArrayFillRand para inteiros
void ArrayFillRand(int* array, int arrayLength, int maxRange, int minRange = 0) {
	// cout << "Inteiro" << endl;
	// Inverte os valores max e min para quando apenas um {arg} for passado.
	int min_range = minRange;
	if (minRange > maxRange) {
		min_range = maxRange;
		maxRange = minRange;
	}

	srand(time(NULL));
	for (int i = 0; i < arrayLength; i++) {
		array[i] = (rand() % ((maxRange + 1) - min_range)) + min_range;
		srand(rand());
		// printf("%d ", array[i]);
	}
}

// ArrayPrint para inteiros
void ArrayPrint(int* array, int arrayLength) {
	cout << "{ ";
	for (int i = 0; i < arrayLength; i++) {
		cout << array[i];
		if (i == arrayLength - 1) {
			cout << " }" << endl;
			break;
		}
		cout << ", ";
	}
}

void SelectionSort(int* array, int size) {

	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (array[minIndex] > array[j]) minIndex = j;
		}
		int swap = array[minIndex];
		array[minIndex] = array[i];
		array[i] = swap;
		ArrayPrint(array, size);
	}
}

void SelectionRecSort(int* array, int size) {

	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (array[minIndex] > array[j]) minIndex = j;
		}
		int swap = array[minIndex];
		array[minIndex] = array[i];
		array[i] = swap;
		ArrayPrint(array, size);
	}
}

int main() {

	int array[3];

	ArrayFillRand(array, arrayLength(array), 100);

	ArrayPrint(array, arrayLength(array));

	SelectionRecSort(array, arrayLength(array));

	ArrayPrint(array, arrayLength(array));

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}