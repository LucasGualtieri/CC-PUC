#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Array {
	int* pointer;
	int size;
} Array;

Array* NewArray(int size) {
	Array* newArray = (Array*)malloc(sizeof(Array));

	newArray->size = size;

	newArray->pointer = (int*)malloc(size * sizeof(int));

	return newArray;
}

void ArrayFillRand(Array* array, int limiteInferior, int limiteSuperior) {
	srand(time(0)); // seed the random number generator
	for (int i = 0; i < 10; i++) {
		array->pointer[i] = (rand() % ((limiteSuperior + 1) - limiteInferior)) + limiteInferior; // generate random number between 0 and 99
	}
}

void ArrayPrint(Array* array) {
	printf("{ ");
	for (int i = 0; i < array->size; i++) {
		printf("%d", array->pointer[i]);
		printf("%s", i < array->size - 1 ? ", " : " }\n");
	}
}

// void MatrixFill(Matrix* matrix) {
// 	int contador = 0;
// 	for (int i = 0; i < matrix->rows; i++) {
// 		for (int j = 0; j < matrix->columns; j++) {
// 			matrix->pointer[i][j] = ++contador;
// 		}
// 	}
// }

#endif