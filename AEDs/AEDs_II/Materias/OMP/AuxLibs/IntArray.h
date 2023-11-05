#ifndef INT_ARRAY_H_
#define INT_ARRAY_H_

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>

#define EOA INT_MAX // End of array

typedef struct IntArray {
	int size, *array;
	bool (*isSorted) (struct IntArray);
	void (*Print) (struct IntArray);
	void (*PrintParcial) (int, struct IntArray);
	void (*Fill) (struct IntArray, int sentinel, ...);
	void (*FillRand) (int lowerLimit, int upperLimit, struct IntArray);
	void (*FillOrdered) (int lowerLimit, int upperLimit, struct IntArray);
	void (*Close) (struct IntArray);
} IntArray;

static int RandInt(int lowerLimit, int upperLimit) {
	static bool seedInitialized = false;
    if (!seedInitialized) {
        srand(time(0)); // clock() also works
        seedInitialized = true;
    }
	return (rand() % ((upperLimit + 1) - lowerLimit)) + lowerLimit;
}

void IntArrayFill(IntArray array, int sentinel, ...) {
	va_list args;
	va_start(args, sentinel);

	int value;
	while ((value = va_arg(args, int)) != sentinel) {
        *(array.array++) = value;
    }
}

void IntArrayFillRand(int lowerLimit, int upperLimit, IntArray array) {
	if (lowerLimit > upperLimit) {
		int aux	 = upperLimit;
		upperLimit = lowerLimit;
		lowerLimit = aux;
	}

	for (int i = 0; i < array.size; i++) {
		array.array[i] = RandInt(lowerLimit, upperLimit);
	}
}

void IntArrayFillOrdered(int lowerLimit, int upperLimit, IntArray array) {
	
	bool ascending = lowerLimit < upperLimit;

	for (int i = 0; i < array.size; i++) {
		
		if (ascending) array.array[i] = lowerLimit++;
		else array.array[i] = lowerLimit--;
	}
}

bool IntArrayIsSorted(IntArray intArray) {

	int N = intArray.size;
	int* array = intArray.array;

	bool result = true;

	for (int i = 0; i < N - 1; i++) {
		if (array[i] > array[i + 1]) {
			result = false;
			i = N;
		}
	}

	return result;
}

void IntArrayPrint(IntArray array) {
	printf("{ ");
	for (int i = 0; i < array.size; i++) {
		printf("%d", array.array[i]);
		printf("%s", i < array.size - 1 ? ", " : " }\n");
	}
}

void IntArrayPrintParcial(int k, IntArray array) {
	printf("{ ");
	for (int i = 0; i < k; i++) {
		printf("%d", array.array[i]);
		printf("%s", i < k - 1 ? ", " : " }\n");
	}
}

void IntArrayClose(IntArray array) {
	free(array.array);
}

IntArray newIntArray(int arraySize) {

	if (arraySize == 0) arraySize = 10;

	IntArray array;
	array.size = arraySize;
	array.array = (int*)malloc(arraySize * sizeof(int));
	array.isSorted = IntArrayIsSorted;
	array.Print = IntArrayPrint;
	array.PrintParcial = IntArrayPrintParcial;
	array.Fill = IntArrayFill;
	array.FillRand = IntArrayFillRand;
	array.FillOrdered = IntArrayFillOrdered;
	array.Close = IntArrayClose;

	return array;
}

// Método com args... para receber os números do array, foo(1,2,3,4,5,6);

#endif