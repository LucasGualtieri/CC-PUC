#ifndef INT_ARRAY_H_
#define INT_ARRAY_H_

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct IntArray {
	int size, *array;
	void (*Print)(struct IntArray);
	void (*FillRand)(int lowerLimit, int upperLimit, struct IntArray);
	void (*FillOrdered)(int lowerLimit, int upperLimit, struct IntArray);
	void (*Close)(struct IntArray);
} IntArray;

int RandInt(int lowerLimit, int upperLimit) {
	static bool seedInitialized = false;
    if (!seedInitialized) {
        srand(time(0)); // clock() also works
        seedInitialized = true;
    }
	return (rand() % ((upperLimit + 1) - lowerLimit)) + lowerLimit;
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
		else array.array[i] = upperLimit--;
	}
}

void IntArrayPrint(IntArray array) {
	printf("{ ");
	for (int i = 0; i < array.size; i++) {
		printf("%d", array.array[i]);
		printf("%s", i < array.size - 1 ? ", " : " }\n");
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
	array.Print = IntArrayPrint;
	array.FillRand = IntArrayFillRand;
	array.FillOrdered = IntArrayFillOrdered;
	array.Close = IntArrayClose;

	return array;
}

#endif